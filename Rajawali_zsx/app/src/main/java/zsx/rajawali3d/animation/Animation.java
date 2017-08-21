package zsx.rajawali3d.animation;

import android.view.animation.Interpolator;
import android.view.animation.LinearInterpolator;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by hasee on 2017/7/31.
 */

public abstract class Animation extends Playable {

    public enum RepeatMode {
        NONE ,
        INFINITE ,
        RESTART ,
        REVERSE ,
        REVERSE_INFINITE;
    }

    protected final List<IAnimationListener> mAnimationListeners;

    protected int mRepeatCount;
    protected double mDelay;//计算动画需要的延迟时间
    protected double mDuration;//计算动画周期
    protected double mStartTime;//记录动画开始时间
    protected Interpolator mInterpolator;
    protected RepeatMode mRepeateMode = RepeatMode.NONE;
    protected boolean mIsReversing;
    protected double mDelayCount;//记录动画当前已经延迟的时间
    protected double mElapsedTime;
    protected double mInterpolatedTime;
    protected int mNumRepeat;
    protected boolean mIsStarted;

    private boolean mIsFirstStart = true;

    public Animation() {
        mAnimationListeners = new ArrayList<IAnimationListener>();
        mInterpolator = new LinearInterpolator();
        mRepeateMode = RepeatMode.NONE;
    }

    protected abstract void applyTransformation();


    @Override
    public void reset() {
        super.reset();

        setState(State.PAUSED);
        mElapsedTime = 0;
        mIsStarted = false;
        mDelayCount = 0;
    }

    public  double getDelayDelta() {
        return mDelay;
    }

    public long getDelayMilliseconds() {
        return (long)(mDelay * 1000d);
    }

    public double getDurationDelta() {
        return mDuration;
    }

    public long getDurationMilliseconds() {
        return (long)(mDuration * 1000d);
    }

    public Interpolator getInterpolator() {
        return mInterpolator;
    }

    public RepeatMode getRepeatMode() {
        return mRepeateMode;
    }

    public void setDelayDelta(double delay) {
        mDelay = delay;
    }

    public void setDelayMilliseconds(long delay) {
        mDelay = delay / 1000d;
    }

    public void setDuration(double duration) {
        mDuration = duration;
    }

    public void setDurationMilliseconds(long duration) {
        mDuration = (long) (duration / 1000d);
    }

    public void setInterpolator(Interpolator interpolator) {
        mInterpolator = interpolator;
    }

    public void setRepeatCount(int repeatCount) {
        mRepeatCount = repeatCount;
    }

    public void setRepeatMode(RepeatMode repeatMode) {
        mRepeateMode = repeatMode;
    }

    public void setStartTime(double startTime) {
        if (startTime < mDuration) {
            mStartTime = startTime;
        } else {
            throw new RuntimeException("ZSX----Animation start time must be less the duration.");
        }
    }

    public void setStartTime(long startTime) {
        setStartTime(startTime/1000d);
    }

    public void update(final double deltaTime) {
        //如果当前动画暂停，则返回
        if (isPaused())
            return;

        //如果当前动画的延迟还没结束
        if (mDelayCount < mDelay) {
            //累计延迟时间，并返回
            mDelayCount += deltaTime;
            return;
        }

        //如果还未开始
        if (!mIsStarted) {
            mIsStarted = true;
            //记录开始时间
            mElapsedTime = mStartTime;
            //触发动画开始事件
            eventStart();
        }

        //动画已经开始，累计动画执行事件---不包含延迟时间
        mElapsedTime += deltaTime;

        final double interpolatedTime = mInterpolator.getInterpolation((float)(mElapsedTime / mDuration));
        mInterpolatedTime = interpolatedTime > 1 ? 1 : interpolatedTime;

        if (mIsReversing)
            mInterpolatedTime = 1 - mInterpolatedTime;

        applyTransformation();

        //更新动画
        eventUpdate(mInterpolatedTime);

        //如果到达动画结束时间
        if (mElapsedTime >= mDuration && !isEnded()) {
            setState(State.ENDED);

            switch (mRepeateMode) {
                case NONE:
                    eventEnd();
                    return;
                case REVERSE_INFINITE:
                    mIsReversing = !mIsReversing;
                case INFINITE:
                    mElapsedTime -= mDuration;
                    play();
                    eventRepeat();
                    break;
                case RESTART:
                    if (mRepeatCount > mNumRepeat) {
                        mNumRepeat ++;
                        reset();
                        play();
                        eventRepeat();
                    } else {
                        eventEnd();
                        return;
                    }
                    break;

                case REVERSE:
                    if (mRepeatCount > mNumRepeat) {
                        mNumRepeat++;

                        mIsReversing = !mIsReversing;

                        reset();
                        play();

                        eventRepeat();
                    } else {
                        eventEnd();
                        return;
                    }

                    break;

                default:
                    throw new UnsupportedOperationException(mRepeateMode.toString());
            }
        }
    }

    protected void eventEnd() {
        for (int i = 0; i < mAnimationListeners.size();i++) {
            mAnimationListeners.get(i).onAnimationEnd(this);
        }
    }

    protected void eventRepeat() {
        for (int i = 0; i < mAnimationListeners.size();i++) {
            mAnimationListeners.get(i).onAnimationRepeat(this);
        }
    }

    protected void eventStart() {
        mIsFirstStart = false;

        for (int i = 0; i < mAnimationListeners.size();i++) {
            mAnimationListeners.get(i).onAnimationStart(this);
        }
    }

    protected void eventUpdate(double interpolatedTime) {
        for (int i = 0; i < mAnimationListeners.size();i++) {
            mAnimationListeners.get(i).onAnimationUpdate(this,interpolatedTime);
        }
    }

    public double getInterpolatedTime() {
        return mInterpolatedTime;
    }
}
