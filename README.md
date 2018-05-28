# ARKitNote

### 一、ARKit三个官方Demo
- BuildingYourFirstARExperience
- CreatingFace-BasedARExperiences
- Handling3DInteractionandUIControlsinAugmentedReality


### 二、UE4中使用ARKit插件的教学视频
Getting_Started_With_ARKit_In_Unreal_Engine4.mp4

### 三、环境要求
- 要求iOS设备的A9及以上处理器，目前支持的机型有iPhone 6s/Plus,iPhone 7/Plus,iPhone 8/Plus,iPhoneX。
- ARKit是基于内置相机的，需要在项目的Info.plist中指定NSCameraUsageDescription 来获取相机的使用权限。

### 四、支持的功能
当前最新版本为1.5，支持的功能如下：
- 世界追踪：根据相机画面，实时计算虚拟世界相对真实世界的位置，从而将虚拟物体摆放到对应的位置。
- 脸部追踪：基于深度相机，追踪脸部的表情及位置等，目前仅iPhoneX支持此功能。
- 光照估算：根据相机捕获的画面，估算当前的光照强度，并将光照量应用到虚拟物体上。
- 平面检测：水平面和竖直平面。
