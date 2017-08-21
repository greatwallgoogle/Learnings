package zsx.rajawali3d.util;

/**
 * Created by hasee on 2017/8/17.
 */

public class ArrayUtils {
    public static double[] convertFloatsToDoubles(float [] input)
    {
        if (input == null) return null;

        double[] output = new double[input.length];
        for (int i = 0; i < input.length; i++)
        {
            output[i] = (double)input[i];
        }

        return output;
    }
}
