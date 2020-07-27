//粒子发射器
#include <string>
#include "ParticleUtility.h"

using namespace ParticleUtility;
class ParticleModule;
class ParticleModuleRequired;

//粒子发射器基类
class ParticleEmitter
{
public:
    ParticleEmitter(){}
    virtual ~ParticleEmitter(){}
    //设置发射器名称
    std::string                         GetEmitterName(){return m_strEmitterName;}
    //获取发射器名称
    void                                SetEmitterName(const std::string& strName){m_strEmitterName = strName;}
    //设置发射器类型
    void                                SetEmitterType(EParticleSystemEmitterType eType){m_eType = eType;}
    //获取发射器类型
    EParticleSystemEmitterType          GetEmitterType(){return m_eType;}
    //克隆
    ParticleEmitter*                    Clone();
    //复制
    ParticleEmitter*                    Dumplicate();
    //添加module
    ParticleModule*		                AddModule(EParticleModuleType eType);
    //移除module
    bool                                RemoveModule(int nIndex);
    //移动module
    bool			                    MoveModule(int nSourceIndex, int nDestIndex);
private:
    std::string                         m_strEmitterName;//发射器名称
    EParticleSystemEmitterType          m_eType;//发射器类型
    ParticleModuleRequired*             m_pModuleRequired;//required模块

};