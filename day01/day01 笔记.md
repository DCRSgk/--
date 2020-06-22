# day01 笔记

## Ep01 C++学习指南

Stay Hungry, Stay Foolish.



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

## Ep06 函数重载 