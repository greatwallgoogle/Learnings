#include <iostream>
#include <vector>
using namespace std;

template<class T>
class MySingleton
{
public:
    static T* GetInstance()
    {
        static T t;
        return &t;
    }
print:
    MySingleton(){}
    MySingleton(const MySingleton<T>&);
    MySingleton& operator=(const MySingleton<T>&);
};

int main()
{
    return 0;
}