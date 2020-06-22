# C++学习日记

[TOC]

# Stay Hungry, Stay Foolish.

# day01

## Ep01 C++学习指南

### 3w方法

> - what：如何使用
>   - 表层
> - how：实现原理
>   - 底层
> - why：设计
>   - 架构

### C++11的特点

> - auto nullptr
> - array unoredered_map
> - 智能指针
> - thread 
> - atomic



> 任何人都能写出机器能看懂的代码，但只有优秀的程序员才能写出人能看懂的代码。



> 有两种写程序的方式：一种是把代码写得非常复杂，以至于“看不出明显的错误”；另一种是把代码写得非常简单，以至于“明显看不出错误”。



>  “把正确的代码改快速”，要比“把快速的代码改正确”，容易得太多。

## Ep02 命名空间

### 定义形式和访问：

- 命名格式

  > - ```c++
  >   namespace xx
  >   {
  >       //xx可以是任意名称
  >   }//命名空间结束
  >   ```

- 访问

  > - 

### 三种适用形式和优缺点

> - 

### 带命名空间的函数声明

### 匿名命名空间

### 命名空间的嵌套

## Ep03 指针常量和常量指针

### 指针常量：const pointer

> - 可以修改指针指向变量的值
>
> - 不可以修改指针的指向
>
> - ```c++
>   
>   ```
>
> - 

### 常量指针：pointer to const

> - 可以修改指针的指向
>
> - 不可修改指针指向变量的值
>
> - ```c++
>   
>   ```
>
> - 

## Ep04  malloc/free与new/delete区别

- malloc申请内存，不会初始化。new申请内存，有初始化
- malloc/free为库函数，new/delete为表达式

## Ep05   引用

本质为对变量起别名

底层是指针

```c++ 
//代码实现：

```



# day02

## Ep01 昨日重现

### const

> - 使用时需要初始化，并且赋值之后不可改变const的值

### 常量指针和指针常量

> - 常量指针：point to const 
>   - 不能修改指针所指变量的值
>   - 可以修改指针指向
> - 指针常量：pointer const
>   - 不能修改指针的指向
>   - 可以修改指针所指变量的值

### const指针常量

> - ```c++
>   const * int const ptr;
>   ```
>
> - 不能修改指针所指变量的值
>
> - 不能修改指针的指向

###  引用

变量的别名，使用之前需要初始化

- 不要返回堆空间的引用，除非有垃圾自动回收机制
- 注意引用的内存泄露问题

### 强制转换

- 少用，甚至不用，特别是dynamic_cast，耗时较高

- 分场景进行，容易查找

> - static_cast
>
>   - 基本数据类型之间的转换
>
>   - void* ==> int*
>
>   - 基类和子类之间指针或者引用的转换
>
>   - 相当于C中的强制类型转换，但没有运行时类型检查来保证转换的安全性。
>
>   - 无法消除常量属性，即**转换之后仍需是常量**
>
>     - ```c++
>       int e = 10;
>        	const int f = 		static_cast<const int>(e);
>        	///正确，将int型数据转换成const int型数据
>        
>        	int g = 20;
>        	const int h = 	static_cast<int>(&g);
>        	//编译错误，static_cast不能转换掉g的const属性
>        
>       ```
>
>   - 针对类而言，推荐上行转换而坚决抵制下行转换
>
>     - 类上行和下行转换：
>
>       ```c++
>       	class Base
>       	{};
>       
>       	Class Derived : public Bace
>       	{	}
>       
>       	Base* pB = new Base();
>       	if(Derived* pD = static_cast<Derived*>(pB))
>       	{}//下行转换不可取
>       	Derived* pD = new Derived();
>       	if(Base* pB = static_cast<Base*>(pD))
>       	{}//上行转换是安全的
>       ```
>
> - const_cast
>
>  - 可用于去除常量属性
>
> - dynamic_cast
>
>  **（特别注意：耗时长，资源消耗大，但有安全检查比static_cast安全）**
>
>  - dynamic_cast< type* >(e)
>
>    - type必须是一个类类型且必须是一个有效的指针
>   - dynamic_cast< type& >(e)
>
>    - type必须是一个类类型且必须是一个左值
>   - dynamic_cast< type&& >(e)
>
>    - type必须是一个类类型且必须是一个右值
>   - **e的类型必须符合以下三个条件中的任何一个：**
>     1、e的类型是目标类型type的公有派生类
>     2、e的类型是目标type的共有基类
>     3、e的类型就是目标type的类型。
>   - 如果一条dynamic_cast语句的转换目标是指针类型并且失败了，则结果为0。
>   - 如果转换目标是引用类型并且失败了，则dynamic_cast运算符将抛出一个std::bad_cast异常(该异常定义在typeinfo标准库头文件中)。
>   - e也可以是一个空指针，结果是所需类型的空指针
>
>  - 类层次间的**上行转换**和**下行转换**
>   - 类之间的交叉转换（cross cast
>
> - reinterpret_cast



## Ep02 函数重载（overload）

### 含义

同一个作用域中，函数名字相同但是参数列表不同的函数

### C++支持函数重载的原因

- C不支持函数重载的原因：

  > - 编译过程中不会给同名函数重命名
  > - 所以如果使用同名函数就会编译错误

- C++支持的原因（name mangling）

  > - 在编译过程中对根据变量数量函数重命名
  >   - 根据参数的类型，顺序，个数来对函数进行重命名
  > - 本质编译后是不同的函数

- 本质：C++针对函数重载优化了编译过程，方便使用同名函数

### 用C的方式编译

- 头加入

- ```c++
  #ifdef __cpulsplus
   	//加入宏识别C++环境，C语言内自动跳过相当于 #if 0
   	extern”C“
   	{
     
   	}//end of extern "C"
   	#endif
  ```

  ```c++
  //引入头文件 便于辨别
  #define EXTERN"C" extern"C" {
  #define END_OF_EXTERN"C }
  ```

### 函数参数的默认值

- 可定义一个参数的默认值，当未传入参数时自动调用默认值

- 一般来说，需从右往左赋值参数值，不可断开

- ```c
  int add(int x = 0,int y = 0, int z = 0)
  {   
      return x + y + z;
  }
  int main()
  {
      cout << "add = "<< add() << endl;
  }
  ```





## Ep03 内联函数

### 特点

- 函数调用的时候，用函数体内的内容进行替换
- 在函数前加 inline
  - 无函数调用开销
- 对于内联函数，声明和实现需要写在一起

## Ep04 异常安全 

### 关键字

- throw：抛出异常
- try：尝试捕获异常
- catch：捕获异常

### throw表达式

```c++
	throw + 语句;	//可以是类，可以是语句块 
```

### try - catch 语句块



## Ep05 C/C++风格字符串

### C风格字符串

- 字符数组

  - ```c
    char str1[] = "hello";
    char str2[] = "world";
    int len1 = sizeof(str1);
    int len2 = sizeof(str2);
    //获取长度
    //以/0结尾，所以长度+1
    
    //拼接字符串
    int len = len1 + len2 - 1;
    char *pStr = (char *)malloc(len);
    strcpy(pStr,str1);
    strcat(pStr,str2);
    //先获取长度并申请内存
    //然后需要先拷贝，后拼接
    //此时结尾仍有/0
    ```

- 字符指针

  - ```C
    char *pStr1 = "hello world";
    //用%s占位符
    //同上
    ```

### C++风格字符串

- ```c++
  #include<string>
  using std::string;
  //加载string实体
  void test1
  {
      string s1 = "hello";
      string s2 = "world";
      string s3 = s1 + s2;
      //直接相加即可拼接
  }
   0 
  
  ```

### C/C++风格字符串的转换

```c++
const char *pStr = s3.c_str();
//将C++风格字符串转换成C风格
```

### 字符串常量的书写

- ```c++
  const char *p = "hello world";
  //用字符指针表示字符串常量
  ```

### 遍历C++风格字符串

- 用字符串的长度遍历（str1.size()）

  - ```c++
    for(size_t ids = 0;idx != s3.size();++idx)
    {
        cout << s3[idx] << endl;
    }
    ```

  - 

- auto遍历

  - ```c++
    for(auto %elem : s3)
    {
        cout << elem << endl;
    }
    ```

  - 

### 字符串的拼接

- 直接进行加减法，加上字符串即可



### 内存分配

- 虚拟地z址空间

  > - 内核
  >
  > - 用户栈：自动分配释放
  >
  >   - 函数参数
  >   - 局部变量
  >
  > - 内存映射段
  >
  >   - 静态库
  >   - 动态库
  >   - 文件映射
  >
  > - 运行时堆
  >
  >   - 手动管理
  >   - malloc/free
  >   - new/delete
  >
  > - 读写段
  >
  >   - 全局/静态区
  >   - 全局/静态变量
  >
  > - 只读段
  >
  >   - 文字常量区：字符串常量
  >   - 程序代码区：存放程序的二进制指令
  >
  >   

- 内核空间（对用户不可见）

  > - 

- 

## Ep06 面向对象（oop）

### 抽象

- 相同属性的对象抽象出来成类（Class）

### 类（class）

```c++
class humanBeing}
{
    public:
    bodyPart()
    {
        hands(){}
        legs(){}
        eyes(){}
        etc.(){}
    }
    bodyFunction()
    {
        walk(){}
        eat(){}
        talk(){}
        hear(){}
        etc.(){}
    }
    private:
}
```



- humanBeing (father class)

  > - bodyPart ：
  >   - hands 
  >   - legs 
  >   - eyes 
  >   - etc.
  > - bodyFunction：
  >   - walk
  >   - eat
  >   - talk
  >   - hear
  >   - etc.

### 继承

- female (subclass of humanBing)

  > -  humanBeing class

- male (subclass of humanBing)

  > -  humanBeing class

- instance(实例)

  > - 类的具体实现
  > - anybody is the instance

### 封装

- 隐藏类的实现细节
- 外界只知道有humanBeing这个类，而不知道如何实现的

### 多态

- 多种状态，比如  walk可以正着走也可以倒着走

struct 默认访问权限为public，class的默认访问权限为private

# day03

## Ep01 对象的创建 -- 构造函数 

### 构造函数

- 函数名和类名相同
- 函数没有返回值
- 没有返回类型，即使是void也不能有

- 在创建对象的时候自动调用，如果没有则由系统提供
- 用于初始化数据成员

```c++
class Print
{
public:
    Point()
    {
        
    }//构造函数
};
```

- 初始化时仅与被声明的顺序相关

## 对象的销毁 -- 析构函数

### 析构函数

- 函数名和类名相同，但是之前冠以~号以区别构造函数

- 如构造函数，也没有返回值也返回类型

- 当对象超出错用于被销毁时，析构函数自动调用

- 完成对象的销毁，执行清理工作

- 手动调用的时候会出现两次析构的问题

- ```c++
  class Print
  {
  public:
      Point()
      {
          
      }//构造函数
      
      ~Point()
      {
          
      }//析构函数
  };
  ```

## 浅拷贝和深拷贝 ？ 

### 浅拷贝





### 深拷贝

