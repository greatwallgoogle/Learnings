#include "ParticleModuleRequired.h"

ParticleModuleRequired::ParticleModuleRequired()
    : ParticleModule()
    , m_bUseLocalSpace(true)
    , m_bEmitterDurationUseRange(true)
    , m_bDelayFirstLoopOnly(true)
    , m_bEmitterDelayUseRange(true)
{
    m_eModuleType = EPMT_Required;
}