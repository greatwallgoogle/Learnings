#pragma once

class Engine;
class Context;

class Application
{
public:
    Application(Context* pContext);
    virtual ~Application();
    //初始化引擎并执行循环
    int          Run();
protected:
    //引擎初始化之前调用
    virtual void Setup(){}
    //引擎初始化之后调用
    virtual void Start(){}
    //主循环结束之后调用
    virtual void Stop(){}
protected:
    Engine*     m_pEngine;
};
