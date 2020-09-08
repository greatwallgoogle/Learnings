#include <iostream>
#include <cstddef>

/*
��Alloctor1�������ǣ�
1. ��operator new/delete��־λstatic����;
2. ʹ��Ƕ��ָ���������;
*/
namespace Alloctor2
{
	class Screen
	{
	public:
		Screen(){}
		~Screen(){}
		static void* operator new(size_t size)
		{
			if (size != sizeof(Screen))
			{
				return ::operator new(size);
			}

			Screen* pRes = nullptr;
			if (NULL == pHeadOfFreeList)
			{
				//����һ����ڴ�
				size_t nChunk = BLOCK_SIZE * sizeof(Screen);
				pHeadOfFreeList = static_cast<Screen*>(::operator new(nChunk));

 				//�ֳ�һƬƬ
				//��һ��д����
// 				for (int i = 0; i < (BLOCK_SIZE - 1); i++)
// 				{
// 					pHeadOfFreeList[i].pNext = &pHeadOfFreeList[i + 1];
// 				}
// 				pHeadOfFreeList[BLOCK_SIZE - 1].pNext = nullptr;
				//////////////////////////////////////////////////////////////////////////
				//�ڶ���д��
				Screen* pCur = pHeadOfFreeList;
				for (int i = 0; i < (BLOCK_SIZE - 1); i++)
				{
					//�����Ƚ�pCurת��Ϊchar*�������ֱ��crash!!!
					pCur->pNext = (Screen*)((char*)pCur + sizeof(Screen));
					pCur = pCur->pNext;
				}
				pCur->pNext = NULL;
			}
			pRes = pHeadOfFreeList;
			pHeadOfFreeList = pHeadOfFreeList->pNext;
			return pRes;
		}
		static void operator delete(void* ptr,size_t size)
		{
			if (nullptr == ptr)
				return;
			if (size != sizeof(Screen))
			{
				::operator delete(ptr);
				return;
			}

			Screen* pCur = static_cast<Screen*>(ptr);
			pCur->pNext = pHeadOfFreeList;
			pHeadOfFreeList = pCur;
		}
	private:
		 static const int BLOCK_SIZE ;
		 static Screen* pHeadOfFreeList;
	private:
		struct ScreenInfo
		{
			unsigned long miles;
			char type;
		};
		union 
		{
			ScreenInfo info;
			Screen* pNext;
		};
	};

	const int Screen::BLOCK_SIZE = 24;
	Screen* Screen::pHeadOfFreeList = NULL;

	void TestAlloc()
	{
		printf("size:%ld \n", sizeof(Screen));
		const int static SIZE = 100;
		const int static PRINT_NUM = 30;
		Screen* p[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			p[i] = new Screen();
		}

		for (int i = 0; i < PRINT_NUM; i++)
		{
			printf("%d %p \n", i,p[i]);
		}

		for (int i = 0; i < SIZE; i++)
		{
			delete p[i];
		}
	}
}


