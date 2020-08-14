#pragma once

class MyArray1
{
public:
	MyArray1(int nCapcity = 16);
	~MyArray1();
	void Insert(int nIndex, int nElement);
	int  Remove(int nIndex);
	void Print();
private:
	//À©ÈÝ
	void Resize();
private:
	int m_nSize;
	int m_nCapcity;
	int* m_pArray;
};