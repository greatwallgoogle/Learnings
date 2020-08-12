#pragma once
#include <string>
#include "ParticleUtility.h"

using namespace ParticleUtility;
class ParticleModule;
class ParticleModuleRequired;
class ParticleModuleSpawn;
class ParticleModuleOrbit;

//粒子发射器基类
//对应UE4的UParticleLODLevel
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
	//获取模块
	ParticleModule*						GetModule(int nIndex);
	//获取模块数量
	int									GetModuleNum();
	
public:
	virtual void						Tick(float fDeltaTime);
private:
	/** The name of particle */
    std::string                         m_strEmitterName;
	/** The type of particle */
    EParticleSystemEmitterType          m_eType;
	/** The required module. */
    ParticleModuleRequired*             m_pModuleRequired;
	/** The SpawnRate/Burst module - required by all emitters. */
	ParticleModuleSpawn* 				m_pSpawnModule;
	/** An array of particle all modules */
	std::vector<ParticleModule*>		m_aModules;
	/** SpawningModules - These are called to determine how many particles to spawn.*/
	std::vector<ParticleModule*> 		m_aSpawningModules;
	/** SpawnModules - These are called when particles are spawned.	*/
	std::vector<ParticleModule*>		m_aSpawnModules;
	/** UpdateModules - These are called when particles are updated.*/
	std::vector<ParticleModule*>		m_aUpdateModules;
	/** These are used to do offsets of the sprite from the particle location. */
	std::vector<ParticleModuleOrbit*> 	m_aOrbitModules;
};