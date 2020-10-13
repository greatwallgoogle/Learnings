#pragma once
//模块类
enum EModuleType
{
	/** General - all emitter types can use it			*/
	EPMT_General,
	/** TypeData - TypeData modules						*/
	EPMT_TypeData,
	/** Beam - only applied to beam emitters			*/
	EPMT_Beam,
	/** Trail - only applied to trail emitters			*/
	EPMT_Trail,
	/** Spawn - all emitter types REQUIRE it			*/
	EPMT_Spawn,
	/** Required - all emitter types REQUIRE it			*/
	EPMT_Required,
	/** Event - event related modules					*/
	EPMT_Event,
	/** Light related modules							*/
	EPMT_Ligh,
	/** SubUV related modules							*/
	EPMT_SubUV,
	EPMT_MAX,
};

class ParticleModule
{
public:
    ParticleModule();
    virtual     ~ParticleModule();
    bool        IsSpawn(){return m_bSpawnModule;}
    bool        IsUpdate(){return m_bUpdateModule;}
    bool        IsEnable(){return m_bEnabled;}
    bool        IsEditable(){return m_bEditable;}

    void        SetEnable(bool bEnable){m_bEnabled = bEnable;}
    void        SetEditable(bool bEdit){m_bEditable = bEdit;}

    EModuleType	GetModuleType() const	{	return m_eModuleType;	}
protected:
    /** If true, the module performs operations on particles during Spawning		*/
	bool        m_bSpawnModule;
    /** If true, the module performs operations on particles during Updating		*/
	bool        m_bUpdateModule;
    /** If true, the module is enabled												*/
	bool        m_bEnabled;
    /** If true, the module has had editing enabled on it							*/
	bool        m_bEditable;
    EModuleType m_eModuleType;
};