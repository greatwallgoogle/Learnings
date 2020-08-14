#include <iostream>

using namespace std;

class S1
{
public:
    void Print()
    {
        printf("S1::Print....\n");
    }
};

class S2:public S1
{
public:
    void Print()
    {
        printf("S2::Print....\n");
    }
};

class S3:public S2
{

};

int main()
{
    S3 s;
    s.Print();
    return 0;
}