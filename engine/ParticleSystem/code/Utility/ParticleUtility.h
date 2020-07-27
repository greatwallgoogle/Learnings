namespace ParticleUtility
{
    enum EParticleSystemEmitterType
    {
        EPARTICLESYSTEM_EMITTER_SPRITE = 0,	/**< 发射公告板的粒子系统  */
        EPARTICLESYSTEM_EMITTER__MODEL,		/**< 发射模型的粒子系统    */
        EPARTICLESYSTEM_EMITTER__RIBBON,		/**< 发射条带的粒子系统    */
        EPARTICLESYSTEM_EMITTER__BEAM,		/**< 发射激光的粒子系统    */
        EPARTICLESYSTEM_EMITTER__ANIMTRAIL,	/**< 发射骨骼条带的粒子系统*/
    };

    enum EParticleModuleType
    {
        PMT_REQUIRED,					/**< Required模块	*/
        PMT_SPAWN,						/**< 发射模块		*/
    };
};