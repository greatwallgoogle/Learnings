#include <iostream>
#include <cstddef>

namespace Alloctor3
{
#define DECLARE_POOL_ALLOC()\
	public:\
		static void* operator new(size_t size){return allocator.Allocate(size);}\
		static void operator delete(void* ptr, size_t size){allocator.DeAllocate(ptr, size);}\
	private:\
		static AllocatorT allocator;\

#define IMPLEMENT_POOL_ALLOC(T) AllocatorT T::allocator;


	class AllocatorT
	{
	public:
		void* Allocate(size_t size)
		{
			Obj* pRes = NULL;
			if (NULL == freeStore)
			{
				size_t chunk = size * BLOCK_SIZE;
				//挖一大块
				freeStore = (Obj*)malloc(chunk);
				//分成一片片
				Obj* pCur = freeStore;
				for (int i = 0; i < (BLOCK_SIZE - 1);++i)
				{
					pCur->pNext = (Obj*)((char*)pCur + size);
					printf("%p  %p \n", pCur, pCur->pNext);
					pCur = pCur->pNext;
				}
				pCur->pNext = NULL;
			}

			pRes = freeStore;
			freeStore = freeStore->pNext;
			return pRes;
		}

		void DeAllocate(void* ptr,size_t size)
		{
			if (ptr)
			{
				((Obj*)ptr)->pNext = freeStore;
				freeStore = ((Obj*)ptr);
			}
		}
	public:
		static const int BLOCK_SIZE = 24;
		struct Obj
		{
			Obj* pNext;
		};
		Obj*	freeStore = NULL;
	};


	class Screen
	{
	public:
		Screen(){}
		~Screen(){}
		DECLARE_POOL_ALLOC()
// 		static void* operator new(size_t size)
// 		{
// 			return allocator.Allocate(size);
// 		}
// 		static void operator delete(void* ptr,size_t size)
// 		{
// 			allocator.DeAllocate(ptr, size);
// 		}
// 	private:
// 		static AllocatorT allocator;
	};
//	AllocatorT Screen::allocator;
	IMPLEMENT_POOL_ALLOC(Screen)


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


