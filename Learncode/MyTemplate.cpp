#include <iostream>
using namespace std;

template <class T>
int compare(const T& v1, const T& v2)
{
    if (v1 > v2)
        return 1;
    if (v1 < v2)
        return -1;
    return 0;
}

template<class T>
inline int min(const T& v1, const T& v2)
{
    if(v1 < v2)
        return v1;
    return v2;
}

template<class Parm, class U>
void fcn(Parm* array,U val)
{
    typename Parm::size_type* ptr;
}

template <class T>
class Queue
{
public:
    void Push(const T& val);
    const T& Front();
};

template<class T, size_t N>
void arrayInit(T (&param)[N])
{
    for (size_t i = 0; i < N; i++)
    {
        param[i] = i;
    }
}

int main()
{
    int arr1[10];
    arrayInit(arr1);
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ",arr1[i]);
    }
    
    return 0;
}