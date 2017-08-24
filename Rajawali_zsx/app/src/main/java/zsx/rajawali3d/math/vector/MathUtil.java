package zsx.rajawali3d.math.vector;

/**
 * Created by hasee on 2017/8/23.
 */

public class MathUtil {

    public static final double PI = Math.PI;

    public static final double PRE_PI_DIV_180 =  PI / 180;

    public static final double PRE_180_DIV_PI = 180 / PI;

    public static double degreeToRadians(final double angle)
    {
        return angle * PRE_PI_DIV_180;
    }

    public static double radiansToAngle(final double radians)
    {
        return radians * PRE_180_DIV_PI;
    }

    public static double clamp(double value, double min, double max)
    {
        return value < min ? min : value > max ? max : value;
    }
}
