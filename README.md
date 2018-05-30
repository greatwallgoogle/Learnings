# ARKitNote

### 一、ARKit官方Demo
#### 1.  ARKit 1.0版本
- BuildingYourFirstARExperience
- CreatingFace-BasedARExperiences
- Handling3DInteractionandUIControlsinAugmentedReality

#### 2. ARKit 1.5版本
- BuildingYourFirstARExperience
- CreatingAnImmersiveARExperienceWithAudio
- CreatingFaceBasedARExperiences
-  Handling3DInteractionAndUIControlsInAugmentedReality
-  RecognizingImagesInAnARExperience
-  UsingVisionInRealTimeWithARKit


### 二、UE4中使用ARKit插件的教学视频
Getting_Started_With_ARKit_In_Unreal_Engine4.mp4

### 三、环境要求
- 要求iOS设备的A9及以上处理器，目前支持的机型有iPhone 6s/Plus,iPhone 7/Plus,iPhone 8/Plus,iPhoneX。
- ARKit是基于内置相机的，需要在项目的Info.plist中指定NSCameraUsageDescription 来获取相机的使用权限。

### 四、支持的功能
当前最新版本为1.5，支持的功能如下：
- 世界追踪：基于后置相机，实时计算相机的状态（可能是相机的位置和旋转，也可能仅仅是旋转，这取决于使用哪种Configuration对象）。这里的相机指的是设备内置的相机，计算相机的状态，实际上也是设备的状态。
- 脸部追踪：基于深度相机，追踪脸部的表情及位置等，目前仅iPhoneX支持此功能。当前版本的脸部检测只能检测一张人脸的信息，如果相机图像中存在多张人脸，ARKit会选择最大或者最清晰可识别的人脸。
- 光照估算：根据相机捕获的画面，估算当前的光照强度，并将光照量应用到虚拟物体上。
- 平面检测：检测相机画面中的水平面和竖直平面。
