package zsx.rajawali3d.animation;

/**
 * Created by hasee on 2017/7/31.
 */

public interface IPlayable {
    public boolean isEnded();

    public boolean isPaused();

    public boolean isPlaying();

    public void pause();

    public void play();

    public void reset();
}
