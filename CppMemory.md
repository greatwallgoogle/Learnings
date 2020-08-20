# 1. 标准库的内存管理接口

## 1.1 分类

内存管理接口自上而下：

![](./pics/memory/mem1.png)

分类：

![](./pics/memory/mem2.png)

使用：

![](./pics/memory/primitives.jpg)



```
 //1. malloc/free
void* p1 = malloc(512);//512 bytes
free(p1);

//2. new/delete
std::complex<int>* p2 = new std::complex<int>();
delete p2;

//3. ::operator new/::operator delete
void* p3 = ::operator new(512);//512 bytes
::operator delete (p3);//注意这个括号，丢失报错

//4. 分配器
int* p4 = std::allocator<int>().allocate(7);//7 ints
std::allocator<int>().deallocate(p4,7);
```

注意：

```c++
//complex代表复数，如2 + 3i
std::complex<int> a{2,3};
```

不可以使用指针调用构造函数，如下面的用法：

```c++
string* ptr = new string();
ptr->string::string("hellos");

//编译报错：
// error: no member named 'string' in 'std::__1::basic_string<char>'
```



## 1.2 new/delete expression

### 1.2.1 new expression

![](./pics/memory/new_expression.jpg)

先分配内存，再调用构造函数。**调用malloc函数分配内存**。

### 1.2.2 delete expression

![](./pics/memory/delete_expression.jpg)

先调用析构函数，再释放内存。**调用free函数释放内存。**

## 1.3 array new / array delete

array new : 创建一个长度为n的数组，分配内存，执行n次构造函数。

array delete:释放一个长度为n的数组，执行n次析构函数，释放内存。

```c++
//Complex是自定义的类，有默认构造函数
Complex* pca = new Complex[3];//执行3次类Complex的构造函数
//...
delete[] pca;//执行3次析构函数
```

array delete与ptr delete的区别在于：

- array delete：是执行n次析构函数
- ptr delete：仅执行一次析构函数

![](./pics/memory/array_new.jpg)

![](./pics/memory/array_new2.jpg)

![](./pics/memory/array_size.jpg)

![](./pics/memory/array_size2.jpg)



## 1.4 placement new（定点new）

**placement new 本身不分配内存，代表将某个对象构建在指定内存上。**

placement new 相当于：```new(ptr)```和```::operator new(size,void*)```。

![](./pics/memory/placement_new.jpg)

用法：

```
char* buf = new char[sizeof(Complex) * 3];
Complex* pc = new(buf) Complex(1,2);
//..
delete[] buf;
```

## 1.5 重载

**一、C++内存分配的执行路径**

​	![](./pics/memory/memory_allo.png)



- ``` new```->```operator new```->```::operator new```->```malloc```。
- ```delete```->```operator delete```->```::operator delete```->```free```。

了解了内存分配的执行路径，知道如何通过函数重载来”接管“内存分配与释放，这就是所谓的所谓的内存管理。

**二、重载::operator new和::operator delete**

::operator new和::operator delete 是一个全局的函数，可以被重载，但很少这么做，因为这是一个全局函数，影响范围较广。

![](./pics/memory/global_operator_new_delete.jpg)

**三、重载operator new 和operator delete**

operator new 和 operator delete 是类的成员函数，本质上是**静态函数**。即便声明函数时，未添加关键字static，编译器被会编译器当做static 函数处理。

![](./pics/memory/overload_op.png)

**四、重载operate new[] 和operator delete[]**

operate new[] 和operator delete[] 分别代表数组内存的分配和释放。

![](./pics/memory/overload_op_arr.png)



**五、new/delete/array new/array delete 重载实例**

![](./pics/memory/overload_tst.png)

使用：

![](./pics/memory/overload_op_use.jpg)

![](./pics/memory/demo.jpg)

## 1.6 内存分配器

### 1.6.1 简单版内存分配器

无论是否添加```static```关键字，```operator new```和```operator delete```是静态函数。

![](./pics/memory/pre_allocator1.jpg)

![](./pics/memory/pre_allocator1_2.jpg)

### 1.6.2 升级版内存池

与第一版非常相似，只是使用了union，并将operator new/delete声明为static。

![](./pics/memory/pre_allocator2.jpg)



![](./pics/memory/pre_allocator2_1.jpg)