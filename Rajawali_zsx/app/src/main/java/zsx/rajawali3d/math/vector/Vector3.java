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

    public Vector3 subtractAndSet(Vector3 u, Vector3 v)
    {
        x = u.x - v.x;
        y = u.y - v.y;
        z = u.z - v.z;
        return this;
    }

    public Vector3 inverse()
    {
        x = -x;
        y = -y;
        z = -z;
        return this;
    }

    public static double dot(Vector3 u, Vector3 v)
    {
        return u.x * v.x + u.y * v.y + u.z * v.z;
    }

    public double dot(Vector3 v)
    {
        return x * v.x + y * v.y + z * v.z;
    }

    public static double length2(double x, double y, double z)
    {
        return (x * x + y * y + z * z);
    }

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
}
