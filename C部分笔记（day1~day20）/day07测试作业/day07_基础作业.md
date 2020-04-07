# 基础作业

### 1当指针变量偏移时，如何确定其地址数值的变化？

- 输出指针所储存的值（地址） = 首地址 + sizeof（elemType)*

### 2 *运算符和[]运算符有什么联系？

- 同级关系，是同一个运算级别，都可以解引用。

### 3利用动态数组，实现类似于C++ vector的push_back功能

- 利用realloc函数

- ```c++
  #include<cstdio>
  #include<string>
  #define CAPACITY 20
  int main()
  {
      char *p=(char*)malloc(CAPACITY);
      char c;
      int i=0,cap=CAPACITY;
      while(scanf("%c",&c)!EOF)
      {
          if(i==cap-2) //需要扩容
          {
              cap=2*cap;
              p=(char*)realloc(p,cap);
          }	
          p[i]=c; //
          i++;
      }
      char push_back;
  	scanf("%c",push_back);
      p[i]=push_back;//原本最后一位填\0 现在填push_back
      p[i+1]=0;
      put(p);
      free(p);
      return 0;
  }
  ```

- 

### 4整理今天课程代码，总结所有导致指针错误的情况

- 指针未初始化：未定义指针的指向
- 指针越界：指向未定义的目的地
- 指针具有多个类型的声明
- 指针引起的内存泄露：使用完指针之后未free
- free后的NULL指针再调用：指针指向的内存已经被释放
- 



 