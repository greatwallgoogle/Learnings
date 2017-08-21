package zsx.rajawali3d;

import zsx.rajawali3d.math.vector.Matrix4;
import zsx.rajawali3d.math.vector.Quaternion;
import zsx.rajawali3d.math.vector.Vector3;
import zsx.rajawali3d.scenegraph.IGraphNode;
import zsx.rajawali3d.scenegraph.IGraphNodeMember;

/**
 * Created by hasee on 2017/8/8.
 */
//http://www.cnblogs.com/wangjq/archive/2012/07/06/2579244.html
public abstract class ATransformable3D implements IGraphNodeMember {
    protected final Matrix4 mMMatrix = new Matrix4();

    protected final Vector3 mPosition;
    protected final Vector3 mScale;
    protected final Quaternion mOrientation;
    protected final Quaternion mTmpOrientation;
    protected final Vector3 mTempVec = new Vector3();
    protected final Vector3 mUpAxis;

    //看向目标点的向量
    protected Vector3 mLookAt;
    //是否看向最新的目标点
    protected boolean mLookAtValid = false;
    //是否自动看向目标点
    protected boolean mLookAtEnabled;
    //是否是相机对象
    protected boolean mIsCamera;
    //如果为true，表示矩阵会重新计算
    protected boolean mIsModelMatrixDirty = true;
    //默认在图形外面
    protected boolean mInsideGraph = false;
    protected IGraphNode mGraphNode;


    public ATransformable3D()
    {
        mLookAt = new Vector3(0);
        mLookAtEnabled = false;
        mPosition = new Vector3();
        mScale = new Vector3(1, 1, 1);
        mOrientation = new Quaternion();
        mUpAxis = new Vector3(Vector3.Y);
    }

    protected void makeModelMatrixDirty()
    {
        mIsModelMatrixDirty = true;
    }

    public boolean onRecalculateModelMatrix(Matrix4 parentMatrix)
    {
        if (mIsModelMatrixDirty)
        {

        }
    }

    public void calculateModelMatrix(final Matrix4 parentMatrix)
    {
        mMMatrix
    }
}
