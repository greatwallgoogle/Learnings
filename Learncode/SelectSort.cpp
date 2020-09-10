#include <iostream>
#include <cstddef>
using namespace std;

/*选择排序要点：
1. 执行n-1趟比较；
2. 每趟遍历中，仅查找剩余元素中最小值的索引；查找到最小值索引后，与当前趟第一个元素交换；保证最左侧的元素都是当前趟的最小值；
3. 时间复杂度O(n2),空间复杂度O(1),稳定排序
*/

void SelectSort(int data[],int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if(data[j] < data[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
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
    SelectSort(data,size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
    
    
    return 0;
}