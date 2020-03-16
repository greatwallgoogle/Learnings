local handModel = {
	    mActor = nil,
	    mActorPath = nil,
	    mScene = nil,
        mActor = nil,
	    mSkeleton = nil,
	    mWorld = nil,
        mCamera = nil
}


function handModel:loadScene(scene,actorPath)

    self.mScene = scene
    self.mWorld = self.mScene:GetWorld()
    self.mActor = self.mWorld:CreateActor(XEStaticMeshActor.ACTOR_TYPENAME)

    local  modelComponent = self.mActor:GetRootComponent()
    modelComponent:LoadAsset(actorPath)
    self.mActor:SetActorLocation(XVECTOR3(0.0))
    local pInstance = modelComponent:GetModelInstance()
    self.mSkeleton = pInstance:GetSkeleton()

    print("LoadAsset function Over")

    self:initListener()
end


function handModel:initListener()
    local handListener = xe.HandEventListener:Create()
    handListener:RegisterHandler(function(hands, event)
        self:controlByHands(hands, event)
    end, xe.Handler.EVENT_HAND_CALLBACK)

    -- print("self.config.particles[1].name");
    -- print(self.config.particles[1].name);
    xe.Director:GetInstance():GetEventDispatcher():AddEventListener(handListener, self.mActor)

end


function handModel:controlByHands(hands, event)

    if #hands >= 1 then
        local hand = hands[1]
        local params3D = hand.m_arrParams;
        local num = #params3D
        if num == 0 then
            print(num .. "*****NO Hand****");
            return
        end

        local landMarks = hand.m_arrLandmarks;
        if #landMarks == 0 then
            print(num .. "*****NO landMarks****");
            return
        end

        self:loadHand3DModel(params3D)

        params3D = nil
        collectgarbage("collect")
        collectgarbage("collect")
    end

end



function handModel:setRelative( name,eularAngle )

    local bone = self.mSkeleton:GetBone(name)

    if bone ~= nil then

        print("BoneName" .. name .. eularAngle.x ..eularAngle.y .. eularAngle.z)
        local quat_ = XQUATERNION() 
        XEMath.EulerToQuaternion(eularAngle.x,eularAngle.y,eularAngle.z,quat_)
        local originalMatrix = bone:GetOriginalMatrix()
        local mat_ = quat_:ConvToMatrix()

        local newMat = mat_*(originalMatrix)
        bone:SetRelativeTM(newMat)
        print("Over Founction Func")

    end

end

function handModel:TransformMatrixFromQLS(quatR ,vL ,vS)
    local tf = XETransform()
    tf:SetScale(vS)
    tf:SetQuaternion(quatR)
    tf:SetLocation(vL)
    return tf:GetTransform();
end

function handModel:ApplySkeletonRootMatrix(pBoneTryToApply ,matWorldNew)
    assert(pBoneTryToApply)

    local matWorldParent = matWorldNew;
    local vScale = XEMath.GetScaleFromMatrix(pBoneTryToApply:GetAbsoluteTM())
    XEMath.ScaleMatrixWorld(matWorldParent, vScale)
    local pBone = pBoneTryToApply:GetParentPtr()
    local pBoneSelf = pBoneTryToApply

    while pBone ~= nil
    do
        local mat = pBoneSelf:GetRelativeTM()
        matWorldParent = mat:GetInverse()*(matWorldParent)
        pBoneSelf = pBone
        pBone = pBone:GetParentPtr()
    end

    if pBone ~= nil then
        local matRoot = pBoneSelf:GetRelativeTM()
        matWorldParent = matRoot:GetInverse()*(matWorldParent)
    end

    return matWorldParent
end

function handModel:loadHand3DModel(data)

    --todo 索引变动
    self:setRelative("finger5joint3", XVECTOR3(data[26], 0.0, 0.0));
    self:setRelative("finger5joint2", XVECTOR3(data[25], 0.0, 0.0));
    self:setRelative("finger5joint1", XVECTOR3(data[24], 0.0, data[23]));
    self:setRelative("finger4joint3", XVECTOR3(data[22], 0.0, 0.0));
    self:setRelative("finger4joint2", XVECTOR3(data[21], 0.0, 0.0));
    self:setRelative("finger4joint1", XVECTOR3(data[20], 0.0, data[19]));
    self:setRelative("finger3joint3", XVECTOR3(data[18], 0.0, 0.0));
    self:setRelative("finger3joint2", XVECTOR3(data[17], 0.0, 0.0));
    self:setRelative("finger3joint1", XVECTOR3(data[16], 0.0, data[15]));
    self:setRelative("finger2joint3", XVECTOR3(data[14], 0.0, 0.0));
    self:setRelative("finger2joint2", XVECTOR3(data[13], 0.0, 0.0));
    self:setRelative("finger2joint1", XVECTOR3(data[12], 0.0, data[11]));
    self:setRelative("finger1joint3", XVECTOR3(data[10], 0.0, 0.0));
    self:setRelative("finger1joint2", XVECTOR3(data[9], 0.0, 0.0));
    self:setRelative("finger1joint1", XVECTOR3(data[8], 0.0, data[7]));

        local quat = XQUATERNION(data[3], data[4], data[5], data[6]);
        local pos = XVECTOR3(data[0],data[1],data[2])
        local mat4 = self:TransformMatrixFromQLS(quat,pos,XVECTOR3(10.0))

        local worldCameraMat4 = self.mCamera:GetViewMatrix():GetInverse()

         commentUtils.printLog("worldCameraMat4", worldCameraMat4)

    local vetor3 = XEMath.GetScaleFromMatrix(worldCameraMat4)
    commentUtils.printLog("vetor3x", vetor3.x)
    commentUtils.printLog("vetor3y", vetor3.y)
    commentUtils.printLog("vetor3z", vetor3.z)

    --commentUtils.printLog("worldMat11", worldCameraMat4.m[1][1])
    --commentUtils.printLog("worldMat12", worldCameraMat4.m[1][2])
    --commentUtils.printLog("worldMat13", worldCameraMat4.m[1][3])
    --commentUtils.printLog("worldMat14", worldCameraMat4.m[1][4])
    --commentUtils.printLog("worldMat21", worldCameraMat4.m[2][1])
    --commentUtils.printLog("worldMat22", worldCameraMat4.m[2][2])
    --commentUtils.printLog("worldMat23", worldCameraMat4.m[2][3])
    --commentUtils.printLog("worldMat24", worldCameraMat4.m[2][4])
    --commentUtils.printLog("worldMat31", worldCameraMat4.m[3][1])
    --commentUtils.printLog("worldMat32", worldCameraMat4.m[3][2])
    --commentUtils.printLog("worldMat33", worldCameraMat4.m[3][3])
    --commentUtils.printLog("worldMat34", worldCameraMat4.m[3][4])
    --commentUtils.printLog("worldMat41", worldCameraMat4.m[4][1])
    --commentUtils.printLog("worldMat42", worldCameraMat4.m[4][2])
    --commentUtils.printLog("worldMat43", worldCameraMat4.m[4][3])
    --commentUtils.printLog("worldMat44", worldCameraMat4.m[4][4])


    mat4 = mat4*(worldCameraMat4)

        mat4 = self:ApplySkeletonRootMatrix(self.mSkeleton:GetBone("metacarpals"),mat4)
        XEMath.EliminateScaleFromMatrix(mat4)
        self.mActor:ApplyWorldTransform(mat4)

        print("loadHand3DModel Over")

end

print("handModel Load Success")

return handModel

