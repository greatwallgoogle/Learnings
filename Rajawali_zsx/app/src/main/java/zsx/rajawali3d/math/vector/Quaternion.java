package zsx.rajawali3d.math.vector;

/**
 * Created by hasee on 2017/8/8.
 */

public final class Quaternion implements Cloneable {
    public static final double NORMALIZATION_TOLERANCE = 1e-6;
    public static final double PARALLEL_TOLERANCE = 1e-6;
    public double w, x, y, z;

    private Vector3 mTmpVec1 = new Vector3();
    private Vector3 mTmpVec2 = new Vector3();
    private Vector3 mTmpVec3 = new Vector3();

    private static final Quaternion sTmp1 = new Quaternion(0, 0, 0, 0);
    private static final Quaternion sTmp2 = new Quaternion(0, 0, 0, 0);

    public Quaternion()
    {
        identity();
    }

    public Quaternion(double w, double x, double y, double z)
    {
        setAll(w, x, y, z);
    }

    public Quaternion(Quaternion quat)
    {
        setAll(quat);
    }

    /*根据旋转轴(单位向量)和旋转角(弧度)，转化为四元数形式
    * w = cos(angle / 2)
    * x = sin(angle / 2) * axis.x;
    * y = sin(angle / 2) * axis.y;
    * z = sin(angle / 2) * axis.z;
    * */
    public Quaternion fromAngleAxis(Vector3 axis, double angle)
    {
        if (axis.isZero())
        {
            return identity();
        }
        else
        {
            mTmpVec1.setAll(axis);
            if (!mTmpVec1.isUnit())
            {
                mTmpVec1.normalize();
            }

            double radian = MathUtil.degreeToRadians(angle);
            double halfAngle = radian * 0.5;
            double halfAngleSin = Math.sin(halfAngle);
            w = Math.cos(halfAngle);
            x = mTmpVec1.x * halfAngleSin;
            y = mTmpVec1.y * halfAngleSin;
            z = mTmpVec1.z * halfAngleSin;
            return this;
        }
    }

    public Quaternion setAll(Quaternion quat)
    {
        return setAll(quat.w, quat.x, quat.y, quat.z);
    }

    public Quaternion setAll(double w, double x, double y, double z)
    {
        this.w = w;
        this.x = x;
        this.y = y;
        this.z = z;
        return this;
    }

    public Quaternion identity()
    {
        w = 1;
        x = 0;
        y = 0;
        z = 0;
        return this;
    }

    public Quaternion lookAt(Vector3 lookAt, Vector3 upDirection)
    {
        mTmpVec1.setAll(lookAt);
        mTmpVec2.setAll(upDirection);
        final double dotProduct = Vector3.dot(lookAt, upDirection);
        final double dotError = Math.abs(Math.abs(dotProduct) - lookAt.length() * upDirection.length());

        if (dotError <= PARALLEL_TOLERANCE)
        {
            mTmpVec2.normalize();
            if (dotProduct < 0)
            {
                mTmpVec1.inverse();
            }

        }
    }

    public Quaternion fromRotationBetween(Vector3 u, Vector3 v)
    {
        final  double dot = u.dot(v);
        final double dotError =
    }
}
