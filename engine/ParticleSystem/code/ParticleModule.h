#pragma once
//模块类
class ParticleModule
{
public:
    bool        IsSpawn(){return m_bSpawnModule;}
    bool        IsUpdate(){return m_bUpdateModule;}
    bool        IsEnable(){return m_bEnabled;}
    bool        IsEditable(){return m_bEditable;}

    void        SetEnable(bool bEnable){m_bEnabled = bEnable;}
    void        SetEditable(bool bEdit){m_bEditable = bEdit;}
private:
    /** If true, the module performs operations on particles during Spawning		*/
	bool        m_bSpawnModule;
    /** If true, the module performs operations on particles during Updating		*/
	bool        m_bUpdateModule;
    /** If true, the module is enabled												*/
	bool        m_bEnabled;
    /** If true, the module has had editing enabled on it							*/
	bool        m_bEditable;
};