#include <iostream>
#include <cstddef>
#include <vector>
#include <math.h>
using namespace std;

//桶排序

//获取数组的最大值和最小值，用来确定范围
void GetMinAndMax(int data[],int size,int& min,int& max)
{
    for (int i = 0; i < size; i++)
    {
        max = data[i] > max ? data[i] : max;
        min = data[i] < min ? data[i] : min;
    }
}

int GetMiddle(vector<int>& data,int left,int right)
{
    int val = data[left];
    while (left < right)
    {
        while (left < right && data[right] >= val)
        {
            right--;
        }
        data[left] = data[right];
        while (left < right && data[left] <= val)
        {
            left++;
        }
        data[right] = data[left];
    }
    data[left] = val;
    return left;
}

void QuickSort(vector<int>& data,int left,int right)
{
    if(left < right)
    {
        int middle = GetMiddle(data,left,right);
        QuickSort(data, left, middle - 1);
        QuickSort(data, middle + 1, right);
    }
}

//计数排序
void BucketSort(int data[],int size)
{
    int min = 0,max = 0;
    GetMinAndMax(data,size,min,max);

    vector<vector<int> > buckets;
    int bucketCount = floor((max - min) / size) + 1; 
    // printf("min : %d mac:%d bucketCount:%d \n",min,max,bucketCount); 
    buckets.resize(bucketCount);
    //拆分为多个桶
    for (int i = 0; i < size; i++)
    {
        int index = (data[i] - min) / size;
        buckets[index].push_back(data[i]);
    }
    
    //分别对每个桶执行快速排序
    for (int i = 0; i < buckets.size(); i++)
    {
        QuickSort(buckets[i],0,buckets[i].size()-1);
    }
    
    //获取桶内排好序的序列
    int index = 0;
    for(int i = 0;i < buckets.size(); i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            data[index++] = buckets[i][j];
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
    BucketSort(data,size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
    //0, 1, 1, 2, 3, 3, 3, 4, 4, 5, 5, 6, 7, 7, 8, 9, 9, 9, 9, 10
    
    return 0;
}