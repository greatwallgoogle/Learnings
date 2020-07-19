#include <iostream>
#include <vector>
#include <thread>
using namespace std;

void greeting()
{
    cout <<"multi thread !"<< endl;
}

void 
int main()
{
    thread t1(greeting);
    t.join();
    return 0;
}