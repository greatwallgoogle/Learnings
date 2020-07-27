#include <map>
#include <string>
#include <vector>
using namespace std;
class ParticlePool;
class ParticleSystemTemplate;
class ParticleSystemInstance;
class ParticleEmitter;
class ParticleModule;

//粒子特效管理器
class Manager
{
public:
    //构造函数
    Manager(/* args */){}
    //析构函数
    ~Manager(){ }
	//初始化 
	bool			            Initialize();
	//释放资源
	void			            Release();
    //根据模板文件创建一个特效实例
	ParticleSystemInstance*	    GetParticleInstance(const std::string& strTemplateFile);
    //新建一个特效实例，在内存中直接创建
	ParticleSystemInstance*	    CreateParticleInstance(const std::string& strTemplateFile);
    //将一个Template对象存到硬盘
	bool			            SaveParticleTemplate(const std::string& strTemplateFile, ParticleSystemTemplate* pTemplate);
    //释放粒子实例资源
	void					    ReleaseParticleInstance(ParticleSystemInstance* pInstance);
    //释放粒子模板资源
	void					    ReleaseParticleTemplate(ParticleSystemTemplate* pTemplate);
public:
    //对模板执行修改后，同步所有的实例

    //添加发射器后调用函数
	void					    OnEmitterAdded(ParticleSystemTemplate* pTemplate, ParticleEmitter* pEmitter);
    //删除发射器后调用函数
	void					    OnEmitterRemoved(ParticleSystemTemplate* pTemplate, ParticleEmitter* pEmitter);
    //复制发射器后调用函数
	void					    OnEmitterDumplicate(ParticleSystemTemplate* pTemplate);
    //移动发射器后调用函数
	void					    OnEmitterMoved(ParticleSystemTemplate* pTemplate);
    //添加模块后调用函数
	void					    OnEmitterAdded(ParticleSystemTemplate* pTemplate, ParticleEmitter* pEmitter, ParticleModule* pModule);
public:
    //获取粒子内存分配器
	ParticlePool*			    GetParticlePool(){ return m_pParticlePool; }
protected:
    //根据模板路径获取粒子模板
	ParticleSystemTemplate*		GetParticleTemplate(const std::string& strTemplateFile);
	//根据路径读取文件并创建粒子模板
	ParticleSystemTemplate*		CreateParticleTemplate(const std::string& strTemplateFile);
private:
	ParticlePool*			                                        m_pParticlePool;    /**< 全局粒子池 */
	map<string, ParticleSystemTemplate*>			                m_mapTemplates;	    /**< 路径——粒子模板 表 */
	map<ParticleSystemTemplate*, vector<ParticleSystemInstance*>>	m_mapFxInstances;	/**< 粒子模板——粒子实例数组 表 */
};