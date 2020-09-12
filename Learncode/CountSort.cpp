#include <iostream>
#include <cstddef>
using namespace std;

//获取数组内某个元素出现的次数
int GetElement(int data[],int size,int val)
{
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res = data[i] == val ? (res + 1) : res;
    }
    return res;
}

//获取数组的最大值和最小值，用来确定范围
void GetMinAndMax(int data[],int size,int& min,int& max)
{
    for (int i = 0; i < size; i++)
    {
        max = data[i] > max ? data[i] : max;
        min = data[i] < min ? data[i] : min;
    }
}
//计数排序
void CountSort(int data[],int size)
{
    int min = 0,max = 0;
    GetMinAndMax(data,size,min,max);
    int temp[max + 1];
    for (int i = min; i <= max; i++)
    {
        temp[i] = GetElement(data,size,i);
    }

    int index = 0;
    for (int i = min; i <= max; i++)
    {
        while (temp[i] > 0)
        {
            data[index++] = i;
            temp[i]--;
        }
    }
}

int main()
{
    // int data[] = {9, 3, 5, 4, 9, 1, 2, 7, 8, 1, 3, 6, 5, 3, 4, 0, 10, 9, 7, 9};
    int data[] = {9, 6, 5, 10, 9, 8,10,7,8};
    int size = sizeof(data)/sizeof(int);
    printf("==========orign \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    CountSort(data,size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
    //0, 1, 1, 2, 3, 3, 3, 4, 4, 5, 5, 6, 7, 7, 8, 9, 9, 9, 9, 10
    
    return 0;
}