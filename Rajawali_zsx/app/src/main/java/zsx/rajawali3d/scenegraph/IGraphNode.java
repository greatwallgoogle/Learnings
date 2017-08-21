package zsx.rajawali3d.scenegraph;

import java.util.Collection;
import java.util.Vector;

import zsx.rajawali3d.math.vector.Vector3;

/**
 * Created by hasee on 2017/8/8.
 */

public interface IGraphNode {
    public enum GRAPH_TYPE
    {
        NONE,
        OCTREE
    }

    public void addObject(IGraphNodeMember object);

    public void addObjects(Collection<IGraphNodeMember> objects);

    public void removeObject(IGraphNodeMember object);

    public void removeObjects(Collection<IGraphNodeMember> objects);

    public void updateObject(IGraphNodeMember object);

    public void addChildrenRecursively(boolean recursive);

    public void removeChildrenRecursively(boolean recursive);

    public void rebuild();

    public void clear();

    //TODO : 参数不完整
    public void cullFromBoundingVolume();

    //TODO : 参数不完整
    public void displayGraph();

    //TODO : vector3不完整
    public Vector3 getSceneMinBound();

    //TODO : Vector3不完整
    public Vector3 getSceneMaxBound();

    public int getObjectCount();

    //TODO:参数不完整
    public boolean contains();

    //TODO:参数不完整
    public boolean isContainedBy();

}
