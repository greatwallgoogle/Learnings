package zsx.rajawali3d.math.vector;

/**
 * Created by hasee on 2017/8/30.
 */

public class Matrix {
    private final static double[] sTemp = new double[32];

    //数组每四个值组成矩阵的一列
    public static void MultiplyMM(double[] result, int  resultOffset,
                                  double[] lhs, int lhsOffset, double[] rhs,
                                  int rhsOffset)
    {
        String message = null;
        if (result == null) {
            message = "Result matrix can not be null.";
        } else if (lhs == null) {
            message = "Left hand side matrxi can not be null.";
        } else if (rhs == null) {
            message = "Right hand side matrix can not be null,";
        } else if ((resultOffset + 16) > result.length) {
            message = "Specified result offset would overflow the passed result matrix.";
        } else if ((lhsOffset + 16) > lhs.length) {
            message = "Specified left hand side offset would overflow the passed lhs matrix.";
        } else if ((rhsOffset + 16) > rhs.length) {
            message = "Specified right hand side offset would overflow the passed rhs matrix.";
        }

        if (message != null) {
            throw new IllegalArgumentException(message);
        }

        double sum = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                sum = 0;
               for (int k = 0; k < 4; k++) {
                   sum += lhs[i + k * 4 + lhsOffset] * rhs[j * 4 + k + rhsOffset];
               }
               result[j * 4 + i + resultOffset] = sum;
            }
        }
    }
}
