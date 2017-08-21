package zsx.rajawali3d.animation;

/**
 * Created by hasee on 2017/7/31.
 */

public interface IAnimationListener {

    public void onAnimationEnd(Animation animation);

    public void onAnimationRepeat(Animation animation);

    public void onAnimationStart(Animation animation);

    public void onAnimationUpdate(Animation animation, double interpolatedTime);
}
