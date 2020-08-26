#pragma once

#include "RefCounted.h"
//Urho3D执行上下文。提供对子系统、对象工厂和属性以及事件接收者的访问。
class Context 
    :public RefCounted
{
public:
    Context();
    ~Context();
};

