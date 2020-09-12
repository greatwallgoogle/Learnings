#include <iostream>
#include <cstddef>
using namespace std;

//快速排序

//将数组分为大于和小于基准值的两部分
int partition(int arr[],int left,int right)
{
    int pivot = arr[left];
    while (left < right)
    {
        while (left < right && arr[right] > pivot)
        {
            right--;
        }
        arr[left] = arr[right];
        while (left < right && arr[left] < pivot)
        {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}

void QuickSort(int data[],int left, int right)
{
    if(left < right)
    {
        int middle = partition(data,left,right);
        QuickSort(data,left,middle - 1);
        QuickSort(data,middle + 1,right);
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
    QuickSort(data,0,size-1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
    
    
    return 0;
}