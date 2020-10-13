#include "ParticleModule.h"

ParticleModule::ParticleModule()
    : m_eModuleType(EPMT_MAX)
	, m_bSpawnModule(true)
	, m_bUpdateModule(true)
	, m_bEnabled(true)
	, m_bEditable(true)    
{

}

ParticleModule::~ParticleModule()
{

}