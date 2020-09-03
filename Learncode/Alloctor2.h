#include <iostream>
#include <cstddef>

/*
与Alloctor1的区别是：
1. 将operator new/delete标志位static函数;
2. 使用嵌入指针和联合体;
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
			if (pHeadOfFreeList)
			{
				pRes = pHeadOfFreeList;
				pHeadOfFreeList = pRes->pNext;
			}
			else
			{
				//申请一大块内存
				size_t nChunk = BLOCK_SIZE * sizeof(Screen);
				Screen* pNewBlock = static_cast<Screen*>(::operator new(nChunk));
				//分成一片片
				for (int i = 0; i < (BLOCK_SIZE - 1); i++)
				{
					pNewBlock[i].pNext = &pNewBlock[i + 1];
				}
				pNewBlock[BLOCK_SIZE - 1].pNext = nullptr;
				pRes = pNewBlock;
				pHeadOfFreeList = &pNewBlock[1];
			}
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


