#include <iostream>
using namespace std;

int main()
{
    static int nNum = 10;
    int a[nNum][nNum];
    for(int i = 0;i < nNum;i++)
    {
        a[i][0] = a[i][i] = 1;
    }

    for(int i = 2;i < nNum;i++)
    {
        for(int j = 1;j < i; j++)
        {
            a[i][j] = a[i - 1][j - 1] + a[i -1][j];
        }
    }

    for(int i = 0;i < nNum;i++)
    {
        //printf("*****************");
        for(int j = 0;j <= i;j++)
        {
            printf("%d   ",a[i][j]);
        }
        printf("\n");
    }

    printf("hello world");
    return 0;
}