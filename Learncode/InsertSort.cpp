#include <iostream>
#include <cstddef>
using namespace std;

/* 插入排序要点：
1. 对于未排序的元素，从已排序的数组中从后往前扫描，将当前元素插入到合适的位置。
2. 合适位置是指，此位置的前一个元素小于待插入的值，后一个元素大于待插入的值。
*/

void InsertSort(int data[],int size)
{
    for (int i = 1; i < size; i++)
    {
        int nValidIndex = i;
        int temp = data[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if(data[j] > temp)
            {
                nValidIndex = j;
            }
        }

        //插入到合适位置
        if(nValidIndex != i)
        {
            //全部元素后移一位
            for (int j = i - 1;j >= nValidIndex;j--)
            {
                data[j + 1] = data[j];
            }
            data[nValidIndex] = temp;
        }
    }
}

int main()
{
    int data[] = {1,9,4,6,10,3};
    int size = sizeof(data)/sizeof(int);
    printf("==========orign \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    InsertSort(data,size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
    
    
    return 0;
}