day02_作业

一、选择题
1、在（C/E）情况下适宜采用inline定义内联函数。(多选题)
A、 函数体含有循环语句    

B、 函数体含有递归语句
C、 函数代码少、频繁调用  

D、 函数代码多、不常调用
E、 需要加快程序执行速度

二、简答题
1. 如何判断一段程序是由C 编译程序还是由C++编译程序编译的？

- 通过nm查看函数名入口，C无重载而C++有

- 定义固定宏语句：__cplusplus

- ```c++
  #ifdef __cplusplus  std::cout << "c++";
  #else std::cout << "c";
  #endif
  ```

2. 函数重载的原理是什么？

- 在预处理的时候根据函数参数重命名函数

3. inline函数与带参数的宏定义的区别？

- 没听懂，明天重新听

三、写出下面程序结果。
1、设有如下程序结构：
class Box
{ … 
};
void main()
{
	Box A,B,C; 
}
该程序运行时调用3__次构造函数；调用 __3次析构函数。

2、写出以下程序运行的结果。

i=0,k=2
i=0,k=2

```c++
#include <iostream>
using namespace std;
class Sample {
public:
      Sample();
      void Display();
private:
      int i;
      static int k;
};
Sample::Sample() 
{
	i=0;
	k++;
}
void Sample::Display() 
{
   cout << "i=" << i << ",k=" << k << endl;
}

int Sample::k=0;
int main( ) 
{
    Sample a, b;
    a.Display();
    b.Display();
    return 0;
}
```



3、写出以下程序运行的结果。（ ）

Constructor1
Constructor2
i=0
i=10
Destructor
Destructor

```C++
#include <iostream>
using namespace std;
class Sample 
{
	int i;
public:
	Sample();
	Sample(int val);
	void Display();
	~Sample();
};
Sample::Sample() 
{
	cout << "Constructor1" << endl;
	i=0;
}

Sample::Sample(int val) 
{
	cout << "Constructor2" << endl;
   i=val;
}
void Sample::Display() 
{
   cout << "i=" << i << endl;
}
Sample::~Sample() 
{
   cout << "Destructor" << endl;
}
int main() 
{
     Sample a, b(10);
     a.Display();
     b.Display();
     return 0;
}
```



4、写出下列程序的运行结果。

i = 0, k = 2
i = 0, k = 2

```C++
#include<iostream>
using namespace std;
class Sample
{
private:
	int i;
	static int k;
public:
	Sample();
	void Display();
};
int Sample::k = 0;
Sample::Sample() { i = 0; k++; }
void  Sample::Display() 
{ 
	cout << "i = " << i << ", k = " << k << endl; 
}
void main()
{
	Sample a, b;
	a.Display();
	b.Display();
}
```



四、改错题。
例题1：分析找出以下程序中的错误，说明错误原因，给出修改方案使之能正确运行。

```c++
#include<iostream>

using std::cout;
using std::endl;

class Base
{ 
	//int a1,a2;此处为非公开变量，不可被调用
public:
	//Base(int x1 = 0, x2 = 0);
    //此处仅给了函数声明为给函数定义 
    int a1,a2;
    Base(int x1 = 0, x2 = 0)
    {
        
    }
};

int main(void)
{
	Base data(2,3);
 	cout << data.a1 << endl;
 	cout << data.a2 << endl;
    //此处不能访问a1，a2，因为a1，a2为Base类的非公开变量，仅限类内使用
    //修改a1，a2到public类内便可以使用
	return 0;
}
```





例题2：分析以下程序的错误原因，给出修改方案使之能正确运行。

```c++
#include <iostream>
class Base
{
    float ix,iy;
public:
 Base(float ix,float iy)
 {
	_ix = ix;
	_iy = iy;
 }
 	float gain();
};

Base::float gain()
{ 
	return iy/ix; 
}
int main(void)
{
	Base base(5.0,10.0);
 	cout << "The gain is => " << gain() << endl;
}
```



五、编程题。
1、定义一个学生类，其中有3个数据成员：学号、姓名、年龄，以及若干成员函数。
同时编写main函数使用这个类，实现对学生数据的赋值和输出。

```c++
#include<iostream>
#include<string>
std::cout;
std::endl;
std::string;
class:student
{
public:
    void stuNum(int num)
    {
        _stuNum = num;
    }
    void stuName(char *name)
    {
        _stuNum = name;
    }
    void stuAge(int age)
    {
        _stuNum = age;
    }
	void stuPrint()
    {
        cout<<"num:"<<_num<<endl;
        cout<<"name:"<<_name<<endl;
        cout<<"age:"<<_age<<endl;
    }   
private:
    int _stuNum;
    string _stuNum;
    int _stuNum;
};
int main()
{
    student stu;
    stu.stuNum(7777);
    stu.stuName("clearLove");
    stu.stuAge(4396);
	stu.stuPrint();
    return 0;
}
```

