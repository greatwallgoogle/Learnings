#include <iostream>
#include <cstddef>
using namespace std;

/*冒泡排序要点：
1. 执行n-1趟比较；
2. 每趟遍历中，仅比较相邻两个元素的值；
3. 时间复杂度O(n2),空间复杂度O(1),稳定排序
*/

void BubbleSort(int data[],int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 0; j < (size - 1 - i); j++)
        {
            if(data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
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
    BubbleSort(data,size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
    
    
    return 0;
}