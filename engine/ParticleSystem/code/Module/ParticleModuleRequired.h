#pragma once

#include "ParticleModule.h"

class ParticleModuleRequired : public ParticleModule
{
public:
    ParticleModuleRequired(/* args */);
    ~ParticleModuleRequired();
    
private:
    /** If true, update the emitter in local space										*/
	bool            m_bUseLocalSpace;
    /**
	 *	If true, select the emitter duration from the range
	 *		[EmitterDurationLow..EmitterDuration]
	 */
	bool            m_bEmitterDurationUseRange;//work not

    /**
	 *	The low end of the emitter duration if using a range.
	 */
	float           m_fEmitterDurationLow;//work not

    /** 
	 *	How long, in seconds, the emitter will run before looping.
	 */
	float           m_fEmitterDuration;

    //
	// Delay-related.
	//

    /**
	 *	Indicates the time (in seconds) that this emitter should be delayed in the particle system.
	 */
	float           m_fEmitterDelay;

    /** 
	 *	The low end of the emitter delay if using a range.
	 */
	float           m_fEmitterDelayLow;

    /**
	 *	If true, select the emitter delay from the range 
	 *		[EmitterDelayLow..EmitterDelay]
	 */
	bool            m_bEmitterDelayUseRange;

    /**
	 *	If true, the emitter will be delayed only on the first loop.
	 */
	bool            m_bDelayFirstLoopOnly;

    /** The number of times to loop the emitter.
	 *	0 indicates loop continuously
	 */
	int             m_nEmitterLoops;
};