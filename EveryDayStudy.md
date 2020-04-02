# 一、C++模块

## 1.1 C++基础

### 1.1.1 public/private/protected

#### 1.1.1.1 三种标号的访问范围

- private声明的属性，只能被以下情况访问：
  - 所属类中的函数
  - 其友元函数访问
- protected声明的属性，只能被下列情况访问：
  - 所属类中的函数
  - 子类的函数
  - 其友元函数
- public 声明的属性，只能被下列情况访问：
  - 所属类中的函数
  - 子类的函数
  - 其友元函数
  - 该类的对象

#### 1.1.1.2 三种标号的继承

**private属性(成员变量和成员函数)不能被继承。**

- private继承：父类的protected和public属性(成员变量和成员函数)在子类中都会变为private。
- protected继承：父类的protected和public属性(成员变量和成员函数)在子类中都会变为protected。
- public继承：父类的protected和public属性(成员变量和成员函数)不发生变化。





## 1.2 C++进阶

### 1.2.1 默认构造函数的构建操作

#### 1.2.1.1 带有默认构造函数的Member Class Object

- 若一个类无任何构造函数，但它内含一个成员类对象，而后者有默认构造函数，那么这个类的implict default constructor（隐式默认构造函数）就是“nontrivial”（有用的），编译器将为此类合成一个inline的默认构造函数，此合成操作只有在构造函数真正需要被调用时才会发生。
- 当一个类包含多个成员类对象时
  - 若此类无任何构造函数，则编译器会自动合成一个默认构造函数。当调用此构造函数时，编译器将按照成员类对象声明的顺序依次调用各个默认构造函数。
  - 若此类有默认构造函数，则调用此函数时，编译器将按照成员类对象声明的顺序依次调用对应的构造函数（可能是默认构造函数，也肯能是含参数的构造函数）。
  - 若此类有多个构造函数，无默认构造函数，则编译器将不会合成默认构造函数，而是调用每个现有构造函数时，都会执行 默认构造函数的操作（即按照成员类对象声明的顺序依次调用其默认构造函数 ）。
  - 无论是程序员实现的构造函数，还是编译器合成的默认构造函数，无论成员类对象在构造函数内初始化的顺序如何，其构造函数的调用顺序都是按照声明的顺序执行

#### 1.2.1.2 带有默认构造函数的Base Class（基类）

若一个无任何构造函数的类派生自一个带有默认构造函数的基类，则编译器将为此派生类合成一个"notrivial"的默认构造函数，它将调用上一层基类默认构造函数（根据声明顺序）。

#### 1.2.1.3 带有一个虚函数的类

需要合成默认构造函数的情况

- 类声明一个虚函数
- 类派生自一个继承串链，其中有一个或更多的虚基类
- 不管哪种情况，只有缺乏用户声明的构造函数，编译器会自动合成一个默认构造函数

#### 1.2.1.4 带有一个虚基类的类

为了避免菱形继承，如下图所示，A继承X和B继承B时均需采用虚继承方式。

![extend](./pics/extend.png)



总结：

- 编译器必须为未声明构造函数的类声明默认构造函数的四种情况：
  - 包含成员类对象
  - 基类中包含默认构造函数
  - 包含虚函数
  - 采用虚继承
- 在合成的默认构造函数中，只有基类子对象和成员类对象会被初始化，所有其他的非静态数据成员，如整数、整数指针、整数数组等等都不会被初始化，为了避免野指针情况，程序员务必为非静态指针变量赋初值。
- 多态仅针对于指针和引用有效，对变量或对象无效。

### 1.2.2 复制构造函数的构建操作

#### 1.2.2.1 复制构造函数定义

复制构造函数是一个构造函数，第一个参数的类型是当前类的类型，可以有多个参数，其第二参数及后继参数需提供一个默认值。

#### 1.2.2.2 三种调用复制构造函数的情况

- 类对象的赋值操作```X x1; X x2 = x1; ```

- 当类对象作为参数传给函数时，```void func1(X tmp);```

- 当类对象作为函数返回值时，

  ```X func2(){```

  ​    ```X xt;```

  ​    ```return xt;```

  ```}```

#### 1.2.2.3 复制构造函数的实现方式

定义class时，分为两种情况：

- 开发人员明确声明复制构造函数及其成员变量的赋值。
- 开发人员没有明确声明复制构造函数，由编译器自动合成，其内部是通过defualt memberwise initializaiton完成，即把每一个内建或派生的成员变量的值，从某个object拷贝一份到另一个object。但是它不会拷贝成员类对象，而是以递归的方式施行memberwise initializaiton。参考**《Inside the c++ object model》一书的P49**

通过代码说明内建变量的拷贝：

```c++
class Test1
{
public:
    Test1(){}
    Test1(int tmp,std::string strTmp):m_nLen(tmp),m_strTmp(strTmp){}
    //没有声明复制构造函数
public:
    int m_nLen;
    std::string m_strTmp;
};

Test1 t1(5,"hello");
Test1 t2 = t1;
printf("test :%d  %s",t2.m_nLen,t2.m_strTmp.c_str()); //结果为>> test :5  hello

//跟下面操作一致
t2.m_nLen = t1.m_nLen;
t2.m_strTmp = t1.m_strTmp;
```



将Test1对象作为Test2的成员变量，来说明非内建对象的拷贝：

```c++
class WordTmp
{
public:
    int nVal;
    Test1 t1;
};

WordTmp tTVal2;
WordTmp.nVal = 2;
WordTmp.t1 = t1;

WordTmp tTVal3 = tTVal2;
```

如果将```tTVal2```赋值给```tTVal3```，```WordTmp```的```default memberwise initialization```会拷贝其内建的成员```nVal```，然后再对```Test1``` 类型的成员变量```t1```执行```default memberwise initialization```操作。

#### 1.2.2.4 位逐次拷贝（Bitwise Copy Semantics）

没看明白。。。



#### 1.2.2.5 虚函数表

只要一个类声明了一个或多个虚函数，编译期间必然会执行的两个操作：

- 增加一个虚函数表(vtbl)，内含每一个有作用的虚函数的地址。
- 为类对象(或指针)分配一个指向虚函数表的指针(vptr)。

**重要概念：切割（sliced）**

```
//这将会发生切割行为
DerivedClass dObj1;
BaseClass    bObj2 = dObj1;
```

此时bObj2会丢失属于DerivedClass的部分，bObj2本质上是BaseClass类型的对象。

实际上是因为合成出来的基类复制构造函数会明确设定bObj2的虚函数指针（vptr）指向基类的虚函数表，而不是直接直接拷贝右手边派生类对象的vptr。

#### 1.2.2.6 位逐次拷贝无效的情况

1. 当class内含一个成员对象，而后者的class声明有一个复制构造函数时；
2. 当class继承自一个基类，而后者存在有一个复制构造函数时（无论是被明确声明还是被合成）；
3. 当class声明了一个或多个虚函数时；
4. 当class派生自一个继承串链，其中有一个或多个虚基类时。
   - 一个类对象如果以另一个对象作为初值，而后者有一个virtual base class subobject，那么会使“bitwise copy semantics”失效，换句话说，这个问题不发生在一个类对象以另一个同类的object作为初值，而是发生在 一个类对象以其派生类object作为初值时。
   - ![virtual base class subobject](./pics/virtual_base_class_subobject.png)

### 1.2.3 程序转化语意

#### 1.2.3.1 明确的初始化

```
X x0;
X x1(x0); //编译器实际执行的是复制构造函数操作  x1.X::X(x0)
X x2 = X(x0);//编译器实际执行的是复制构造函数操作  x2.X::X(x0)
```

#### 1.2.3.2 参数的初始化

C++标准中指出，将一个类对象作为参数传给一个函数，或作为一个函数的返回值，相当于以下形式的初始化操作：

```
//temp代表参数(返回值)，而arg代表真正的参数值。
X temp = arg;
```

**即编译器调用复制构造函数时定义一个临时对象，然后将临时对象传给函数，或作为返回值返回。**

```
X xx;
foo(xx);

//编译器对复制构造函数的调用过程为
X __temp0;
__temp0.X::X(xx);
foo(__temp0);
//此时foo的定义发生改变，变为void foo(X& x0)； 其中class X 声明了一个析构函数，会在foo()函数完成之后被调用，释放临时对象__temp0。
//疑问：如果形参为指针呢？也会调用指针的析构函数？
```

#### 1.2.3.3 返回值的初始化

以下面这段代码为例，说明函数执行过程：

```
X foo()
{
    X x1;
    //process...
    return x1;
}

//调用函数
X xx = foo();
```

x1作为函数返回值返回实际上有一个双阶段转化过程：

- 第一步，首先生成一个X 类型的引用。
- 第二步，在return 指令之前，执行一个复制拷贝构造函数，将想要返回的对象作为第一步创建引用的初值。

其真正的执行过程是：编译器会改写这个函数，使它不返回任何值，而是将想要返回的对象作为形参引用对象返回。

foo() 函数的转化如下：

```
void foo(X& __res)
{
    X x1;
    x1.X::X();//执行默认构造函数
    
    //process..
    
    __res.X::X(xx);///执行复制构造函数
    return;
}

//实际上的调用形式会被转化：
X xx;
foo(xx);
```

考虑下面三种情况下构造函数的执行过程：

```
X x1(1024);
X x2 = X(1024);
X x3 = (X)1024;
```

上述第一行代码明确被单一的构造函数设定初值：

```
x1.X::X(1024);
```

而第二行和第三行代码，提供了两个步骤的初始化操作：

```
X __temp;
__temp.X::X(1024);//调用含参构造函数
x2.X::X(__temp);//调用复制构造函数
__temp.X::~X();//临时对象调用析构函数
```

### 1.2.4 初始化列表

#### 1.2.4.1 什么是初始化列表

初始化列表位于类的构造函数中，以冒号开头，以分号分隔多个初始化字段。

```
class Apple
{
public:
	Apple(int nId,string strName):id(nId),name(strName){}; //初始化列表
private:
	int id;
	string name;
}
```

#### 1.2.4.2 必须使用初始化列表的情况

1. 当初始化一个引用对象时；
2. 当初始化一个const对象时；
3. 当调用一个基类的含参构造函数时；
4. 当调用一个member class 的含参构造函数时。



变量初始化的次序：

```
class Word
{
public:
	Word():m_nCount(0),m_strCont("hello"){}
private:
	std::string m_strCont;
	int m_nCount;
};
```

上述代码中，虽然在初始化列表中，```m_nCount```位于```m_strCont```之前，但实际上是先初始化```m_strCont```，因为这两个变量声明的次序是先声明```m_strCont```。

**类成员变量的初始化顺序由其声明顺序决定，而不是在初始化列表中的排序。**

编译器会对初始化列表一一处理并可能重新排序，以反映出成员的声明次序，同时它会在构造函数内插入一些代码。



思考问题：

```
class X{ };
class Y : public virtual X{ };
class Z : public virtual X{ };
class A : public Y, public Z { };

int main()
{
    printf("X:%ld Y:%ld Z:%ld A:%ld \n",sizeof(X),sizeof(Y),sizeof(Z),sizeof(A));
    return 0;
}
```

在VS Code中打印出的结果为：```X:1 Y:8 Z:8 A:16 ```。

一个空的class X，其sizeof的值为1，是因为它有一个隐含的1``byte``，是被编译器插入进去的一个```char```，这使得这个类的两个对象得以在内存中拥有独一无二的地址：

````
X a,b;
if(&a == &b) 
	printf("ok \n");
elses
	printf("no \n");//结果为no
````



### 1.2.5 类内变量的布局

类的非静态变量在类对象中的排列顺序与其被声明的顺序相同，任何中间插入的静态数据变量都不会被放进类对象的布局之中。

以代码为例：

```
class Point3D
{
private:
	float x;
	static List<Point3D*>* freeList;
	float y;
	static const int chunkSize = 200;
	float z;
};
```

每一个Point3D对象都是由三个float变量组成，次序是```x,y,z```。静态变量```freeList / chunkSize```都不会被放进Point3D对象的布局之中，而是存在于程序的```data segment```中。

```C++ Standard```要求在同一个访问区段（即```private/public/protected```）中，变量的排序只需符合“较晚出现的变量在类对象中有较高的地址”这一个条件即可。



编译器还可能会合成一些内部使用的成员变量，如```vptr```，即虚函数指针，当前所有的编译器都把它安插在每一个“内含虚函数的类”的对象中。传统上，vptr会被放置在所有明确声明的成员变量之后，不过也有一些编译器把vptr放在一个类对象的最前端。



```C++ Standard```允许编译器将多个访问区段的变量自由排列，不必在乎它们出现在类声明中的次序。

```
class Point3D
{
private:
	float x;
	static List<Point3D*>* freeList;
private:
	float y;
	static const int chunkSize = 200;
private:
	float z;
};
```

上述代码中，Point3D 类对象的**大小和组成**与先前声明的那个相同，但是成员变量的排列次序则由编译器而定。

### 1.2.6 类内变量的存取

```
Point3D origin, *pt = &origin;
origin.x = 10;
pt->x = 10;
```

思考：上述对于x存取的两种方式有什么重大差异吗？

#### 1.2.6.1 静态类型

静态变量只有一个实体，并不在类对象中，而是存放在程序的data segment之中。

```
origin.chunkSize = 250;
pt->chunkSize = 250;
Point3D::chunkSize = 250;
```

上述三种方式的调用结果完全相同，只是```.```和```->```只是语法上的一种方便访问的方式。

#### 1.2.6.2 非静态类型

非静态变量直接存放在每个类对象之中。想要对一个非静态变量进行存取操作，编译器需要把类对象的起始地址加上变量的偏移量(offset)。举例说明：

```
origin.y = 0;
```

则地址&origin.y将等于：

```
&origin + (&Point3D::y - 1);
```

> 注意其中的-1操作。指向成员变量的指针，其偏移量总是被加上1，这样可以使编译器区分出“一个指向成员变量的指针，用以指出类的第一个成员”和“一个指向成员变量的指针，没有指出任何成员”两种情况。

没看明白引用的这段话。。。

**每一个非静态成员变量的偏移量在编译时期即可获知，即便成员变量属于基类也是如此。**



**非静态变量在虚继承中的存取效率**

```
Point3D* pt3d;
pt3d->x = 0;
```

其执行效率在x是一个结构体变量、类成员变量、单一继承、多重继承的情况下完全相同。但如果x是一个虚基类的成员变量，则存取速度会慢一点。



现在回想本节最开始的问题，通过对象和指针存取成员有什么重大差异？

```
Point3D origin, *pt = &origin;
origin.x = 10;
pt->x = 10;
```

答案为：当```Point3D```是一个派生类，并且被存取的成员变量(如x)是从虚基类中继承而来时，就会存在重大的差异。因为pt的具体类型在执行期才能明确，经由一个额外的间接导引才能解决。但如果使用origin，其类型确定为``Point3D``，即便它继承自虚基类，成员变量的偏移量也在编译时期就固定了。



### 1.2.7 继承与成员变量

分为四种情况介绍：单一继承且不含虚函数、单一继承并含虚函数、多重继承、虚继承。

#### 1.2.7.1 只要继承不要多态

定义没有继承关系的```Point2D```和```Point3D```两个类：

```
class Point2d
{
public:
	float x;
	float y;
};

class Point3d
{
public:
	float x;
	float y;
	float z;
};
```

这两个类没有虚函数，它们的布局与结构体完全一样。

![point2d_3d](./pics/point2d_3d.png)

这种方式下，对于x和y的操作需要分别在```Point2D```和```Point3D```两个类中实现，从设计模式上来讲，这种设计是不优雅的，一般通过继承方式。

```
class Point2d
{
public:
	Point2d(float nX = 0,float nY = 0):_x(nX),_y(nY){}
	float getX(){return _x;}
	void  setX(float nT){_x = nT;}
	float getY(){return _y;}
	void  setY(float nY){_y = nY;}
protected:
	float _x;
	float _y;
};

class Point3d : public Point2d
{
public:
	Point3d(float nX = 0,float nY = 0,float nZ = 0)
		:Point2d(nX,nY),_z(nZ){ }
	float getZ(){return _z;}
	void  setZ(float nZ){_z = nZ;}
protected:
	float _z;
};
```

单一继承且没有虚函数时的布局为：

![extend_2d_3d](./pics/extend_2d_3d.png)

访问类的sizeof:

```
printf("Point2d: %ld Point3d: %ld\n",sizeof(Point2d), sizeof(Point3d));
//结果为 Point2d: 8 Point3d: 12
//Point2d : 4 + 4
//Point3d : 4 + 4 + 4
```

#### 1.2.7.2 加上多态

加上多态，也就是应用虚函数。代码如下：

```
class Point2d
{
public:
	Point2d(float nX = 0,float nY = 0):_x(nX),_y(nY){}
	float getX(){return _x;}
	void  setX(float nT){_x = nT;}
	float getY(){return _y;}
	void  setY(float nY){_y = nY;}
	
    virtual void setZ(float nZ){}//虚函数
    virtual float getZ(){return 0;}//虚函数
protected:
	float _x;
	float _y;
};

class Point3d : public Point2d
{
public:
	Point3d(float nX = 0,float nY = 0,float nZ = 0)
		:Point2d(nX,nY),_z(nZ){ }
	float getZ(){return _z;}
	void  setZ(float nZ){_z = nZ;}
protected:
	float _z;
};
```

添加了虚函数之后：

- 每一个```Point2d```的类都会导入一个虚函数表，此表用于存放类中所声明的每一个虚函数的地址。
- 每一个```Point2d```和```Point3d```的类对象都会导入一个虚函数指针(vptr)，提供执行期的链接，使每一个对象都能找到对应的虚函数表，这就是多态的本质。

 

```Point2d```和```Point3d```是单一继承关系，加上了虚函数之后的继承布局为：**（此图是把vptr指针放在基类的尾端，现在的编译器一般是放在基类的头部）**

![](./pics/virtual_func.png)

访问类的sizeof（没想明白。。）：

```
printf("Point2d: %ld Point3d: %ld\n",sizeof(Point2d),sizeof(Point3d));
//结果为 Point2d: 16 Point3d: 24
```

疑问：为什么```Point3d```没有所属的虚函数指针，用的却是```Point2d```的虚函数指针。难道是因为```Point3d```类中没有虚函数吗？



#### 1.2.7.3 多重继承

单一继承提供了一种“自然多态”的形式，是关于类体系中的基类和子类之间的转换。

以代码展示多继承体系：

```

class Point2d
{
public:
	//有虚函数，所以Point2d对象中会有vptr
protected:
	float _x;
	float _y;
};

class Point3d : public Point2d
{
public:
	//...
protected:
	float _z;
};

class Vertex
{
public:
    //有虚函数，所以Vertex对象有vptr
protected:
    Vertex* next;
};

class Vertex3d:public Point3d, public Vertex
{
public:
    //...
protected:
    float mumble;
};
```

继承关系为：

![](./pics/mult_extend.png)

对于多重派生对象，将其地址指定给“最左端（也就是第一个）基类的指针”，情况与单一继承时相同，二者都有相同的起始地址。至于第二个或后继的基类的地址指定操作，则需要需改：加上（或减去，如果downcast）介于中间的 ```base class subobjects```的大小。



声明下面四个变量：

```
Vertex3d v3d;
Vertex*  pv;
Point2d* p2d;
Point3d* p3d;
```

当执行下面的操作时（```Vertex```是```Vertex3d```的第二个基类）：

```
pv = &v3d;
//需要进行的内部转化为：
//虚拟C++码
pv = (Vertex*)( ((char*)&v3d) + sizeof(Vertex3d) );
```

而下面的指定操作，都需要简单地拷贝其地址就行了。

```
p2d = &v3d;
p3d = &v3d;
```

如果有两个指针执行如下的操作：

````
Vertex3d* pv3d;
Vertex*   pv;
pv = pv3d;
````

内部不能够只是简单地被转化为：

```
//虚拟C++代码
pv = (Vertex*)((char*)pv3d) + sizeof(Vertex3d);
```

因为当```pv3d```为0时，```pv```将获取```sizeof(Vertex3d)```的值，这是错误的！，因此对于指针，内部转换操作需要有一个条件判断：

```
//虚拟C++代码
pv = pv3d ? (Vertex*)((char*)pv3d) + sizeof(Vertex3d) : 0;
```

至于引用，则不需要针对可能为0值做处理，因为引用不可能为空。



此处多重继承的布局为：

![](./pics/mult_extend_layout.png)

#### 1.2.7.4 虚继承

没看明白。。



### 1.2.8  函数的各种调用方式

C++支持三种类型的成员函数：静态、非静态和虚函数，每一种类型被调用的方式都不同。

以下列代码为例：

```
Point3d Point3d::normalize() const
{
    Point3d res;
    float length = magnitude();
    res.x = x/length;
    res.y = y/length;
    res.z = z/length;
    
    return res;
}

float Point3d::magnitude() const
{
    return sqrt(x * x + y * y + z * z);
}

Point3d obj;
Point3d* ptr;
obj.normalize();
ptr->normalize();
```



#### 1.2.8.1 非静态成员函数

C++ 标准的设计准则之一就是：非静态成员函数至少必须和一般的非成员函数有相同的效率。即选择调用成员函数不应该带来额外负担，编译器内部会将成员函数转化为对等的非成员函数。

```
float magnitude(const Point3d* _this){}
float Point3d::magnitude() const  { }
```

转化步骤为：

1. 改写函数原型：增加一个额外的参数，该额外参数被称为this指针。

   ```
   //非const 非静态成员函数
   Point3d Point3d::magnitude(Point3d* const this)
   
   //const 非静态成员函数
   Point3d Point3d::magnitude(const Point3d* const this)
   ```

2. 将每一个 对非静态成员变量的存取操作 改为经由 ```this```指针来存取：

   ```
   {
       return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
   }
   ```

3. 将成员函数重新写成一个外部函数，对函数名称进行“```mangling```”处理，使其独一无二的存在在程序中。

   ```
   extern magnitude_7Point3dFv(register Point3d* const this);
   ```

经过上述三步就转换结束，其每一个调用操作也都必须转换：

```
//原来的调用
obj.magnitude();
//变成
magnitude_7Point3dFv(&obj);

//而原来的指针调用
ptr->magnitude();
//变成了
magnitude_7Point3dFv(ptr);
```

而上面声明的normalize函数将被改写为：

```
void normalize_7Point3dFv(const Point3d* const this, Point3d& __result){}
```

#### 1.2.8.2 虚拟成员函数

如果```normalize```是虚拟成员函数，则下面的调用：

```
ptr->normalize();
```

将会转化为：

```
(*ptr->vptr[1])(ptr);
```

- vptr是指向虚函数表的指针，每个包含虚函数的类对象都有虚函数指针。
- 其中1是```virtual table slot```的索引值，关联到```normalize```函数。
- 第二个ptr表示this指针。

#### 1.2.8.3 静态成员函数

如果```Point3d::normalize()```是一个静态成员函数，以下的两个调用将会被转化为非成员函数调用：

```
//obj.normalize();
normalize_7Point3dSFV();
    
//ptr->normalize();
normalize_7Point3dSFV();
```

**静态成员函数的主要特性是它没有```this```指针。**

次要特性是：

- 它不能直接存取其所在类的非静态成员变量。
- 它不能被声明为```const```、```virtual```和```volatile```。
- 它不需要经由类对象调用。

> C++ 中 volatile关键字和const对应。<https://zhuanlan.zhihu.com/p/33074506>





#### 1.2.8.4 多态与虚函数

**在C++中，多态表示“以一个基类的指针(或引用)，寻址出一个派生类对象“的意思。**

识别一个类是否支持多态，唯一适当的方法就是看看它是否有虚函数。

**虚函数地址如何被构建起来？**

在C++中，虚函数可以在编译期获知，并且这一组地址是固定不变的，执行期不可能新增或替换之。

- 为了找到表格，每一个类对象都会包含一个由编译器内部产生的指针，指向该表格。
- 为了找到函数地址，每一个虚函数被指派一个固定的索引值。

这些工作都由编译器完成，执行期要做的只是在特定的 ```virtual table slot```(记录着虚函数的地址)中激活虚函数。

一个类只有一个虚表，每一个表内含其对应的类对象中所有```active```虚函数实体的地址，关于激活的虚函数下面进行详细的介绍。

**虚函数表中只记录虚函数、纯虚函数的地址。**

#### 1.2.8.5 单继承下的虚成员函数

声明```Point/Point2d/Point3d```三个类，说明单一继承体系下虚函数表中的内容。

```
class Point
{
public:
	virtual ~Point(){}
    virtual Point& mult(float factor) = 0;
    float x()const {return _x;}
    virtual float y(){return 0;}
    virtual float z(){return 0;}
protected:
    Point(float x = 0){_x = x;}
    float _x;
};
class Point2d:public Point
{
public:
    Point2d(float x = 0,float y = 0):Point(x),_y(y){}
    ~Point2d(){}

    Point2d& mult(float factor);
    float y() const {return _y;}

protected:
    float _y;
};
class Point3d:public Point2d
{
public:
    Point3d(float x = 0,float y = 0,float z = 0):Point2d(x,y),_z(z){}
    ~Point3d(){}

    Point3d& mult(float factor);
    float z() const {return _z;}

protected:
    float _z;
};
```

布局方式：![](/Users/momo/Documents/workspace_script/Learnings/pics/virtual_table.png)

虚函数表中的函数类型包括：

- 继承自基类所声明的虚函数的函数体。基类中该函数实体的地址会被拷贝到派生类虚函数相对应的slot中。
- 派生类使用自己的函数实体。这表示它自己的函数实体地址必须放在对应的slot之中。
- 派生类可以加入一个新的虚函数。此时派生类的虚函数表的尺寸会增加一个slot，新的函数实体地址会被放进该slot之中。
- 一个```pure_virtual_called()```函数实体，即纯虚函数地址。

#### 1.2.8.6 多重继承下的虚函数

在多重继承中支持虚函数，其复杂度围绕着第二个及后继的基类身上，以及”必须在执行期调整this指针“这一点上。

举例：

```
class Base1
{
public:
    Base1();
    virtual ~Base1();
    virtual void speakClearly();
protected:
    float data_base1;
};

class Base2
{
public:
    Base2();
    virtual ~Base2();
    virtual void mumber();
protected:
    float data_base2;
};

class Derived:public Base1,public Base2
{
public:
    Derived();
    virtual ~Derived();
protected:
    float data_derived;
};
```

在多重继承下，一个派生类内含```n-1```个额外的虚表，```n```表示其上一层基类的个数（单一继承将不会有额外的虚表）。

对于本例的派生类，会有两个虚表被编译器产生：

1. 一个主要实体，与Base1（最左端的基类）共享。
2. 一个次要实体，与Base2（第二个基类）有关。

针对每一个虚表，派生类对象中会有对应的```vptr```（虚函数指针）。用以支持”一个类拥有多个虚表“的传统方法是：将每一个表以外部对象的形式产生出来，并给予独一无二的名称。

例如```Derived```所关联的两个表的名称可能是：

```
vtbl_Derived
vtbl_Base2_Derived
```

- 当将一个```Derived```对象的地址指定给一个```Base1```指针或```Derived```指针时，被处理的虚表是主要表格```vtbl_Derived```。
- 当将一个```Derived```对象的地址指定一个```Base2```指针时，被处理的虚表是次要表格```vtbl_Base2_Derived```。

多重继承下的布局：

![](/Users/momo/Documents/workspace_script/Learnings/pics/mult_extend_layout2.png)



#### 1.2.8.7 虚继承下的虚函数



# 二、数据结构与算法

## 2.1 动态规划算法

### 2.1.1 定义

动态规划算法是通过拆分问题，定义问题状态和状态之间的关系，使得问题能够以递推（或分治）的方式去解决。

### 2.1.2 基本思想

由于动态规划解决的问题多数有重叠子问题的特点，为减少重复计算，对每一个子问题只求解一次，将其不同阶段的不同状态保存在一个二维数组中。

### 2.1.3 原理

动态规划的使用条件：**可分解为多个相关子问题，子问题的解被重复使用**。

动态规划的特点：整个问题的最优解取决于子问题的最优解，将子问题称为状态，最终状态的求解归结为其他状态的求解。

### 2.1.4 应用场景

- 计算最大/最小值
- 求可行或不可行
- 求方案总数，若求所有可行的方案，则肯定不能使用动态规划。

### 2.1.5 关于动归的算法题

-  [查找字符串的最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)
- [无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

动态规划算法的分类：

- 线性动归：拦截导弹、合唱队形、挖地雷、建学校、剑客决斗等；
- 区域动归：石子合并、加分二叉树、统计单词个数、炮兵布阵等；
- 树形动归：贪吃的九头龙、二分查找树、聚会的欢乐、数学三角形等；
- 背包问题：01背包问题、完全背包问题、分组背包问题、二维背包、装箱问题、挤牛奶等。

[参考资料](https://www.cnblogs.com/mini-coconut/p/9075277.html)

## 2.2 链表

### 2.2.1 定义

链表是一种在物理上非连续、非顺序的数据结构，由若干个节点组成。

链表分为单链表和双向链表，单链表的每个节点都包含两部分，一部分是存放数据的变量data，另一部分是保存下一个节点的next指针。双向链表的每个节点都包含三部分，除了单链表节点的两部分之外，还包含一个指向前一节点的pre指针。

如果不考虑查找元素过程，只考虑纯粹的插入和删除操作，其时间复杂度为$O(1)$。

### 2.2.2 链表与数组的比较

数组是有限个相同类型的变量所组成的有序集合，在内存中顺序存储的线程表。

|      | 查找   | 插入     | 删除     |
| ---- | ------ | -------- | -------- |
| 数组 | $O(1)$ | $O(n)$   | $O( n )$ |
| 链表 | $O(n)$ | $O( 1 )$ | $O( 1 )$ |

### 2.2.3 关于链表的算法题

- [反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)
- 如何判断链表是否有环？
- 

### 2.3 栈

#### 2.3.1 基本知识

栈是一种逻辑结构，物理上可以基于数组实现，也可以基于链表实现。

特点是先入后出，最早进入的元素称为栈底，最后进入的元素称为栈顶。

基本操作为入栈和出栈。

入栈和出栈的复杂度：$O( 1 )$。因为入栈和出栈只涉及到栈顶元素，不存在其他元素的整体移动，无论是基于数组实现还是链表实现，其复杂度均为$O( 1 )$。

#### 2.3.2 关于栈的算法题



### 2.4 队列

#### 2.4.1 基本知识

队列同栈一样，也是一种既可以基于数组实现，也可以基于链表实现的逻辑结构。

特点是先入先出，队列的出口端成为队头，入口端称为队尾。

入队和出队的复杂度：$O( 1 )$。

#### 2.4.2 关于队列的算法题



### 2.5 散列表

#### 2.5.1 基本知识

散列表又称哈希表，是以键值对的方式成对存储，根据键可以高效的获取值，时间复杂度接近于$O( 1 )$。

哈希表本质上也是一个数组。

## 2.NN 排序算法



### 排序算法复杂度比较

| 排序算法 | 平均时间复杂度 | 最好情况 | 最坏情况 |
| -------- | -------------- | -------- | -------- |
| 冒泡排序 |                |          | O()      |
|          |                |          |          |
|          |                |          |          |



## 2.NN 查找算法



##2.NN 其他算法题

1. 二叉平衡树如何用一维数组存储？
2. 二分查找
3. 树的中序遍历
4. [寻找两个有序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)：用到二分查找

# 三、设计模式





# 四、图形学





# 五、架构设计与引擎



# 六、lua





