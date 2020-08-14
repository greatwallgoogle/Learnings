//理解复制控制成员和构造函数
/*定义一个Exmp类,给出构造函数和复制控制成员，然后用不同方式使用Exmp类型的对象：作为非引用形参和引用形参，动态分配，放在容器中等等，
研究何时使用哪个构造函数和复制控制成员。
*/

#include <iostream>
#include <vector>
using namespace std;

class Exmp
{
public:
	//默认构造函数
	Exmp();
	//复制构造函数
	Exmp(const Exmp& rh);
	//重载赋值操作符
	Exmp& operator= (const Exmp& rh);
	//析构函数
	~Exmp();
};

Exmp::Exmp()
{ 
	cout <<"---- Exmp::Exmp()  defult----"<<this<<endl;
}

Exmp::Exmp(const Exmp& rh)
{
	cout <<"---- Exmp::Exmp(const Exmp&)  copy----"<<this<<endl;
}

Exmp& Exmp::operator= (const Exmp& rh)
{
	cout <<"---- Exmp::operator= (const Exmp&)----"<<endl;
	return *this;
}
Exmp::~Exmp()
{
	cout <<"---- Exmp::~Exmp----"<<this<<endl;
}

///////////////////////////////////////
void TestFunction1(Exmp exmp)//非引用形参，调用复制构造函数生成实参的副本，也就是形成那exmp
{

}

void TestFunction2(Exmp& exmp)//引用形参，此时形参就是实参本身，因为引用时变量的别名
{

}


//奇怪：：怎么打印的日志仅显示步骤1和步骤3，而没用步骤2呢？与C++ Primer上存在差异
Exmp TestFunction3()
{
	Exmp exmp;//1. 调用默认构造函数创建局部对象exmp
	return exmp;//2. 调用复制构造函数创建exmp的副本返回；3. 调用析构函数释放局部对象exmp
}

int main(int argc, char const *argv[])
{
	cout<<"========= 0 =========="<<endl;
	Exmp exmp;//使用默认构造函数

	cout<<"========= 1 =========="<<endl;
	TestFunction1(exmp);//使用复制构造函数初始化形参，使用exmp初始化形参，当方法执行完毕后，形参执行析构函数释放资源

	cout<<"========= 2 =========="<<endl;
	TestFunction2(exmp);//形参为引用，直接传递实参，不调用复制构造函数

	//1. TestFunction3函数内部调用了3个函数，返回Exmp
//	TestFunction3();

	cout<<"========= 3 =========="<<endl;
	//存在疑问？？？？与C++ Primer上存在差异
	exmp = TestFunction3();

	cout<<"========= 4 =========="<<endl;
	Exmp* pExmp = new Exmp();//调用默认构造函数
	delete pExmp;//调用析构函数

	cout<<"============================== 5 start========="<<endl;
	std::vector<Exmp> v(3);//调用3次默认构造函数，然后在函数结束时，调用3次析构函数释放资源，这点跟C++ Primer上不同
	cout<<"============================== 5 end========="<<endl;
	return 0;
}
