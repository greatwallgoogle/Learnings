#include <iostream>

using namespace std;

//主要介绍了拷贝构造函数、友元函数的使用

//***************8第一部分  拷贝构造函数知识  start*******************************
//http://www.runoob.com/cplusplus/cpp-friend-functions.html

//要点1：如果类中包含指针并且动态分配内存时，需要显示定义拷贝构造函数，用于实现值拷贝。
//要点2：什么时候会用到拷贝构造函数？答：(1)使用同类型的其他对象来创建和初始化新的对象时。(2)复制对象并把它作为参数传递给函数时。(3)复制对象并将其从函数返回。
//要点3：拷贝构造函数的写法：classname (const classname &obj){/*函数体*/}

class Line
{
public:
     Line();//无参构造函数
     Line(float fLength);//含参构造函数
     Line(const Line& otherLine);//拷贝构造函数
     float GetLength();
     ~Line();

private:
     float *fLineLength;
     
};

Line::Line():fLineLength(NULL)
{
     cout<<"无参构造函数执行..."<<endl;
}

Line::Line(float fLength)
{
     cout<<"含参构造函数，长度是"<<fLength<<endl;
     fLineLength = new float();
     *fLineLength = fLength;
}

Line::Line(const Line& otherLine)
{
     cout<<"拷贝构造函数执行...."<<endl;
     fLineLength = new float();
     *fLineLength = *otherLine.fLineLength;
}

float Line::GetLength()
{
     return *fLineLength;
}

Line::~Line()
{
     cout<<"析构函数执行.."<<endl;
     delete fLineLength;
     fLineLength = NULL;
}

void Dispaly(Line line)
{
     cout<<"长度："<<line.GetLength()<<endl;
}

void Dispaly2(Line &line)
{
     cout<<"引用参数---长度："<<line.GetLength()<<endl;
}

//***************第一部分  拷贝构造函数知识  end*******************************


//***************第二部分  友元函数知识  start*******************************

//要点一： 友元函数虽然声明在类的定义中，但友元函数并不是类的成员函数，调用友元不需要类的实例，因此友元函数内不能使用this。
//要点二：友元函数可以访问类的私有成员和被保护成员。
//要点三：友元可以是一个函数，也可以是一个类。友元类的成员变量和成员函数都是友元。
class Box
{
public:
     Box();
     ~Box();
     friend void printWidth(Box box);//友元函数
     void SetWidth(float fW);
private:
     float fWeidth;
};

Box::Box(){}

Box::~Box(){}

void Box::SetWidth(float fW)
{
     fWeidth = fW;
}

// 注意：友元函数不是类的成员函数，实现此方法体时，前面不需要添加Box::
void printWidth(Box box)
{
     //因为此函数是Box类的友元函数，因此可以访问Box的私有变量
     cout<<"Box的大小："<<box.fWeidth<<endl;
}


//***************第二部分  友元知识  end*******************************



int main(int argc, char const *argv[])
{
     // Line line0;//调用无参构造函数
     // cout<<"-----------0 "<<endl;
     // Line *line = new Line();  //调用无参构造函数
     // delete line;//调用析构函数
     // line = NULL;  
     // cout<<"-----------1 "<<endl;
     // Line *line2 = new Line(1);//调用含参构造函数
     // cout<<"-----------2 "<<endl;
     // Line line3(*line2);      //调用拷贝构造函数
     // cout<<"-----------3 "<<endl;
     // Line line4(line3);       //调用拷贝构造函数
     // cout<<"-----------4 "<<endl;  
     // delete line2;             //调用析构函数
     // line2 = NULL;

     // Line line(2);                 //调用含参构造函数
     // cout<<"-----------5 "<<endl; 
     // Dispaly(line);                //先调用拷贝构造函数初始化形参，然后执行Display函数体，最后调用析构函数释放形参
     // cout<<"-----------6 "<<endl; 
     // Dispaly2(line);               //直接执行Display函数体，引用是变量的别名，不需要初始化形参
     // cout<<"-----------7 "<<endl; 

     Box box;
     box.SetWidth(20);
     printWidth(box);//不需要Box的对象，可以调用此函数
     return 0;
}