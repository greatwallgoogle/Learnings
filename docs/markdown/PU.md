## 1. ParticleUniverse 核心类

#### 1.1 Particle

Particle类是个虚基类，代表可以被发射的物体。**一个Particle可以被不同的发射器使用。**

Particle有很多种类型，其中可视化粒子是最明显的一种，其他粒子类型可能是发射器、影响器、Technique，甚至是可以被当做粒子的粒子特效(ParticleSystem)。

```C++
enum ParticleType
{
    PT_VISUAL,		//可视化
    PT_TECHNIQUE,	//Technique
    PT_EMITTER,		//发射器
    PT_AFFECTOR,	//影响器
    PT_SYSTEM 		//粒子系统
};
```

成员变量包括：

```C++
ParticleEmitter* 	parentEmitter;//发射当前粒子的发射器，一个粒子可以被多个发射器重用
Vector3 			position;//PU中不区分本地空间和世界空间
Vector3 			direction;//面向和速度
Real 				mass;//粒子质量，可用于模拟不同质量的爆炸粒子
```

