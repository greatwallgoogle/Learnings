#include "MyArray1.h"
#include <assert.h>
#include <memory>

MyArray1::MyArray1(int nCapcity)
	:m_pArray(nullptr)
	, m_nCapcity(nCapcity)
	, m_nSize(0)
{
	m_pArray = new int[m_nCapcity];
}

MyArray1::~MyArray1()
{
	delete m_pArray;
}

void MyArray1::Insert(int nIndex, int nElement)
{
	if (nullptr == m_pArray)
	{
		assert(false && "nullptr == m_pArray");
		return;
	}
	if (nIndex < 0 || nIndex > m_nSize)
	{
		assert(false && "nIndex < 0 || nIndex > m_nSize");
		return;
	}

	if (m_nSize >= m_nCapcity)
	{
		Resize();
	}

	for (int i = m_nSize - 1; i >= nIndex;i--)
	{
		m_pArray[i + 1] = m_pArray[i];
	}

	m_pArray[nIndex] = nElement;
	m_nSize++;
}

int MyArray1::Remove(int nIndex)
{
	if (nullptr == m_pArray)
	{
		assert(false && "nullptr == m_pArray");
		return -1;
	}
	if (nIndex < 0 || nIndex >= m_nSize)
	{
		assert(false && "nIndex < 0 || nIndex >= m_nSize");
		return -1;
	}

	int nElement = m_pArray[nIndex];
	for (int i = nIndex; i < (m_nSize - 1); i++)
	{
		m_pArray[i] = m_pArray[i + 1];
	}
	m_nSize--;
	return nElement;
}

void MyArray1::Print()
{
	for (int i = 0; i < m_nSize;i++)
	{
		printf("index = %d element = %d \n", i, m_pArray[i]);
	}
}

void MyArray1::Resize()
{
	if (nullptr == m_pArray)
		return;

	int* pNewArray = new int[m_nCapcity * 2];
	memcpy(pNewArray, m_pArray, sizeof(int) * m_nSize);
	m_nCapcity = m_nCapcity * 2;
	delete m_pArray;
	m_pArray = pNewArray;
}

