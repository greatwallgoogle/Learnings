package zsx.rajawali3d.math.vector;

/**
 * Created by hasee on 2017/8/8.
 */

public class Vector3 implements Cloneable {
    public double x;
    public double y;
    public double z;


    public static final  Vector3 X = new Vector3(1, 0, 0);

    public static final Vector3 Y = new Vector3(0, 1, 0);

    public static final Vector3 Z = new Vector3(0, 0, 1);

    public static final Vector3 NEG_X = new Vector3(-1, 0, 0);

    public static final Vector3 NEG_Y = new Vector3(0, -1, 0);

    public static final Vector3 NEG_Z = new Vector3(0, 0, -1);

    public static final Vector3 ZERO = new Vector3(0, 0, 0);

    public static final Vector3 ONE = new Vector3(1, 1, 1);

    public static final Vector3 RIGHT_AXIS = X.clone();

    public static final Vector3 UP_AXIS = Y.clone();

    public static final Vector3 FORWARD_AXIS = Z.clone();


    private Vector3 mTmpVector3 = null;

    private Matrix4 mTmpMatrix3 = null;

    public enum Axis {
        X, Y, Z
    }

    public Vector3() {
        x = 0;
        y = 0;
        z = 0;
    }

    public Vector3(double from)
    {
        x = from;
        y = from;
        z = from;
    }

    public Vector3(Vector3 from)
    {
        x = from.x;
        y = from.y;
        z = from.z;
    }


    public Vector3(double x, double y, double z)
    {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public Vector3 setAll(double x, double y, double z)
    {
        this.x = x;
        this.y = y;
        this.z = z;
        return this;
    }

    public Vector3 setAll(Vector3 other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return this;
    }

    public Vector3 setAll(Axis axis)
    {
        return setAll(getAxisVector(axis));
    }

    public Vector3 add(Vector3 v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return this;
    }

    public Vector3 add(double x, double y, double z)
    {
        this.x += x;
        this.y += y;
        this.z += z;
        return this;
    }

    public Vector3 add(double from)
    {
        x += from;
        y += from;
        z += from;
        return this;
    }

    public Vector3 addAndSet(Vector3 u, Vector3 v)
    {
        x = u.x + v.x;
        y = u.y + v.y;
        z = u.z + v.z;
        return this;
    }

    public static Vector3 getAxisVector(Axis axis)
    {
        switch (axis)
        {
            case X:
                return X;
            case Y:
                return Y;
            case Z:
                return Z;
            default:
                throw new IllegalArgumentException("The specified Axis is not a valid choice.--zsx");
        }
    }

    public boolean isZero()
    {
        return (x == 0 && y == 0 && z == 0);
    }

    public boolean isUnit()
    {
        return isUnit(1e-8);
    }

    public boolean isUnit(double margin)
    {
        return Math.abs(length2() - 1) < margin * margin;
    }

    public double length2()
    {
        return (x * x + y * y + z * z);
    }

    //单位化
    public double normalize()
    {
        double mag = Math.sqrt(x * x + y * y + z * z);
        if (mag != 0 && mag != 1)
        {
            double mod = 1 / mag;
            x *= mod;
            y *= mod;
            z *= mod;
        }
        return mag;
    }

    //计算差向量
    public Vector3 subtractAndSet(Vector3 u, Vector3 v)
    {
        x = u.x - v.x;
        y = u.y - v.y;
        z = u.z - v.z;
        return this;
    }

    //反向量
    public Vector3 inverse()
    {
        x = -x;
        y = -y;
        z = -z;
        return this;
    }

    //向量点乘
    public static double dot(Vector3 u, Vector3 v)
    {
        return u.x * v.x + u.y * v.y + u.z * v.z;
    }

    //点乘
    public double dot(Vector3 v)
    {
        return x * v.x + y * v.y + z * v.z;
    }

    //向量模长的平方
    public static double length2(double x, double y, double z)
    {
        return (x * x + y * y + z * z);
    }

    //向量模长
    public double length()
    {
        return length(this);
    }

    public static double length(Vector3 v)
    {
        length(v.x ,v.y, v.z);
    }

    public static double length(double x, double y, double z)
    {
        return Math.sqrt(length2(x, y, z));
    }

    public Vector3 clone()
    {
        return new Vector3(x, y, z);
    }

    //向量叉乘
    public Vector3 crossAndSet(Vector3 u, Vector3 v)
    {
        //类似矩阵计算余子式
        double nx = u.y * v.z - u.z * v.y;
        double ny  =  u.z * v.x - u.x * v.z;
        double nz = u.x * v.y - u.y * v.x;
        return setAll(nx, ny, nz);
    }

    /*
    * 向量u在向量v上的投影向量,公式：
    * result = |u| * cos(夹角) * v
    * ->推导：result = (|u| * dot(u, v) * v) / (|u| * |v|)
    * ->推导：result = (dot(u, v) * v) / |v|
    * */
    public  static Vector3 projectAndCreate(Vector3 u, Vector3 v)
    {
        double dotValue = u.dot(v);
        double dotValue_div = dotValue / v.length();
        return v.clone().multiply(dotValue_div);
    }

    public Vector3 multiply(double value)
    {
        x *= value;
        y *= value;
        z *= value;
        return this;
    }

    public static void orthoNormalize(Vector3 v1, Vector3 v2)
    {
        v1.normalize();
        v2.subtract(projectAndCreate(v2, v1));
        v2.normalize();
    }

    public Vector3 subtract(Vector3 v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return this;
    }
}
