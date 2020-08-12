#pragma once
#include <string>
#include "ParticleUtility.h"

using namespace ParticleUtility;
class ParticleEmitter;

//粒子模板
class ParticleSystemTemplate
{
public:
	ParticleSystemTemplate(){}
	virtual ~ParticleSystemTemplate(){}
	std::string					GetPath(){return m_strPath;}
	int							GetEmitterNum();
	ParticleEmitter*			GetEmitter(int nIndex);
	ParticleEmitter*			AddEmitter(const std::string& strName,EParticleSystemEmitterType eType);
	bool						RemoveEmitter(int nIndex,bool bDelete = true);
	bool						RemoveEmitter(ParticleEmitter* pEmitter,bool bDelete = true);
	bool						MoveEmitter(ParticleEmitter* pEmitter,int nDiff);
	bool						DumplicateEmitter(int nIndex);
	bool						DumplicateEmitter(ParticleEmitter* pEmitter);
private:
	std::string					m_strPath;
};