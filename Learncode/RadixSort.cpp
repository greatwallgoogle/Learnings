#include <iostream>
#include <cstddef>
#include <vector>
#include <math.h>
using namespace std;

//基数排序

//获取最大值
int GetMaxValue(int data[], int count)
{
    int res = 0;
    for (int i = 0; i < count; i++)
    {
        if(data[i] > res)
        {
            res = data[i];
        }
    }
    return res;
}

//计算位数
int GetBit(int val)
{
    int bit = 1;
    while (val >= 10)
    {
        val = val / 10;
        bit++;
    }
    return bit;
}

void RadixCountSort(vector<int>& data,int exp)
{

}

void RadixSort(int data[],int size)
{
    int nMax = GetMaxValue(data,size);
    int bit = GetBit(nMax);
    printf("bit:%d \n",bit);

    //按位由低到高排序
    for (int i = 0; i < bit; i++)
    {
        
    }
    
}

int main()
{
    // int data[] = {9, 3, 5, 4, 9, 1, 2, 7, 8, 1, 3, 6, 5, 3, 4, 0, 10, 9, 7, 9};
    int data[] = {103, 9, 1,7,11,15, 25, 201, 209, 107, 5};
    int size = sizeof(data)/sizeof(int);
    printf("==========orign \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    RadixSort(data,size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
    //0, 1, 1, 2, 3, 3, 3, 4, 4, 5, 5, 6, 7, 7, 8, 9, 9, 9, 9, 10
    
    return 0;
}