package zsx.rajawali3d.math.vector;

import zsx.rajawali3d.util.ArrayUtils;

/**
 * Created by hasee on 2017/8/8.
 */

//TODO:骨架
public final class Matrix4 implements Cloneable {
    /*
    * M00 M01 M02 M03
    * M10 M11 M12 M13
    * M20 M21 M22 M23
    * M30 M31 M32 M33
    */
    public static final int M00 = 0;
    public static final int M01 = 4;
    public static final int M02 = 8;
    public static final int M03 = 12;

    public static final int M10 = 1;
    public static final int M11 = 5;
    public static final int M12 = 9;
    public static final int M13 = 13;

    public static final int M20 = 2;
    public static final int M21 = 6;
    public static final int M22 = 10;
    public static final int M23 = 14;

    public static final int M30 = 3;
    public static final int M31 = 7;
    public static final int M32 = 11;
    public static final int M33 = 15;

    private double [] m = new double[16];
    private double [] mTmp = new double[16];
    private float [] mFloat = new float[16];

    private final Quaternion mQuaternion = new Quaternion();
    private final Vector3 mVec1 = new Vector3();
    private final Vector3 mVec2 = new Vector3();
    private final Vector3 mVec3 = new Vector3();

    private Matrix4 mMatrix;

    public Matrix4()
    {
        identity();
    }

    public Matrix4(Matrix4 matrix4)
    {
        setAll(matrix4);
    }

    public Matrix4 (double [] matrix)
    {
        setAll(matrix);
    }

    public Matrix4(float [] matrix)
    {
        this(ArrayUtils.convertFloatsToDoubles(matrix));
    }

    public Matrix4 setAll(Matrix4 matrix)
    {
        matrix.toArray(m);
        return this;
    }


    public Matrix4 setAll(double [] matrix)
    {
        System.arraycopy(matrix, 0, m, 0 ,16);
        return this;
    }

    public Matrix4 setAll(Vector3 position, Vector3 scale, Quaternion rotation)
    {

    }

    public void toArray(double []doubleArray)
    {
        System.arraycopy(m, 0, doubleArray, 0, 16);
    }

    public Matrix4 identity()
    {
        m[M00] = 1; m[M01] = 0; m[M02] = 0; m[M03] = 0;
        m[M10] = 0; m[M11] = 1; m[M12] = 0; m[M13] = 0;
        m[M20] = 0; m[M21] = 0; m[M22] = 1; m[M23] = 0;
        m[M30] = 0; m[M31] = 0; m[M32] = 0; m[M33] = 1;
        return this;
    }


}
