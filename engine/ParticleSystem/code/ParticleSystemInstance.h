#pragma once
#include <string>
class ParticleSystemTemplate;
class ParticleEmitter;
//粒子实例
class ParticleSystemInstance
{
public:
    ParticleSystemInstance(ParticleSystemTemplate* pTemplate);
    virtual ~ParticleSystemInstance(){}
    virtual void                    Initialize();
    virtual void                    Release();
    virtual void                    Tick(float fScendTime);
    virtual void                    Render();
    virtual ParticleSystemTemplate* GetParticleSystemTemplate(){return m_pTemplate;}
    virtual int                     GetParticleNum(int nEmitterIndex);
    virtual int                     GetParticleNum(ParticleEmitter* pEmitter);
public:
    virtual void                    Play();
    virtual void                    Stop();
    virtual void                    Restart();
    virtual void                    Pause();
    virtual bool                    IsPause();
private:
    ParticleSystemTemplate*         m_pTemplate;
};