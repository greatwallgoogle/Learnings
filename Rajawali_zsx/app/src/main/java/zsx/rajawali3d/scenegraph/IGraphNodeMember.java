package zsx.rajawali3d.scenegraph;

import zsx.rajawali3d.math.vector.Vector3;

/**
 * Created by hasee on 2017/8/8.
 */

public interface IGraphNodeMember {
    public void setGraphNode(IGraphNode node, boolean isInside);

    public IGraphNode getGraphNode();

    public boolean isInside();

    //TODO:返回值类型不完整 IBoundingVolume
    public void getTransformedBoundingVolume();

    public Vector3 getScenePosition();
}
