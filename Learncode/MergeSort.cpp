#include <iostream>
#include <cstddef>
using namespace std;

//归并排序
void MergeSort(int data[],int left,int right)
{
    if(left < right)
    {
        int middle = left + (right - left) / 2;
        int start1 = left;
        int end1 = middle;
        int start2 = middle + 1;
        int end2 = right;
        MergeSort(data, start1,end1);
        MergeSort(data, start2,end2);

        int temp[right + 1];
        int index = left;
        while (start1 <= end1 && start2 <= end2)
        {
            if(data[start1] < data[start2])
            {
                temp[index++] = data[start1++];
            }
            else
            {
                temp[index++] = data[start2++];
            }
        }
        
        while (start1 <= end1)
        {
            temp[index++] = data[start1++];
        }

        while (start2 <= end2)
        {
            temp[index++] = data[start2++];
        }

        for (int i = left; i <= right; i++)
        {
            data[i] = temp[i];
        }
    }
}

int main()
{
    int data[] = {1,9,4,6,10,3};
    int size = sizeof(data)/sizeof(int);
    int reg[size];
    printf("==========orign \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    MergeSort(data,0,size-1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
    
    
    return 0;
}