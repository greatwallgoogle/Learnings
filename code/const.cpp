#include <iostream>

int main()
{
    int i = 1;
    int j = 2;
    const int* p = &i;
    p = &j;
    // *p = 5;

    int* const p2 = &i;

    // p2 = &j;
    printf("p2:%d \n",*p2);
    printf("p:%d \n",*p);

    //printf("sizeof:%d",sizeof(int));
    return 0;
}