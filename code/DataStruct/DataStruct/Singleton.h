#pragma once
#include <mutex>

//线程安全的单例模式，成熟引擎中都是采用这种方式
template<class T>
class Singleton
{
public:
	static T* GetInstance()
	{
		static T _ins;
		return &_ins;
	}
protected:
	Singleton();
	Singleton(const Singleton& other);
	~Singleton();
};

//////////////////////////////////////////////////////////////////////////
//懒汉式模式，非线程安全
template<class T>
class SingleTon1
{
public:
	static T* GetInstance()
	{
		if (NULL == m_pIns)
		{
			m_pIns = new T();
			m_AutoRelease.AutoReleaseTool(m_pIns);
		}
		return m_pIns;
	}
	static void ReleaseInstance()
	{
		if (NULL != m_pIns)
		{
			delete m_pIns;
			m_pIns = NULL;
		}
	}
protected:
	SingleTon1();
	SingleTon1(const SingleTon1& other);
	~SingleTon1();
private:
	static T* m_pIns;
};

template<class T>
T* SingleTon1<T>::m_pIns = NULL;

template<class T>
AutoReleaseTool SingleTon1<T>::m_AutoRelease = nullptr;
//////////////////////////////////////////////////////////////////////////
//饿汉式，线程安全
template<class T>
class SingleTon2
{
public:
	static T* GetInstance()
	{
		if (NULL == m_pIns)
		{
			m_Mutex.lock();
			if (NULL == m_pIns)
			{
				m_pIns = new T();
			}
			m_Mutex.unlock();
		}
		return m_pIns;
	}
protected:
	SingleTon2();
	SingleTon2(const SingleTon2& other);
	~SingleTon2();
private:
	static mutex m_Mutex;
	static T*    m_pIns;
};

//////////////////////////////////////////////////////////////////////////
//饿汉式，线程安全，但未使用时也会分配内存
template < class T> 
class Singleton4
{
public:
	static T* GetInstance()
	{
		return m_pInstance;
	}
	static void ReleaseInstance()
	{
		if (NULL != m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}
private:
	Singleton4();
	~Singleton4();
	Singleton4(const Singleton4& other);
private:
	static Singleton4* m_pInstance = new Singleton4();
};

