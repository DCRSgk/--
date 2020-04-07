# day09

### Ep01 写在前面

- 函数
- 下午复习 完成作业和笔记的修订



### Ep02 函数

- 函数定义and函数声明

  > - 在定义函数之前需要在主程序前声明函数
  > - 在头文件里声明，可省略声明但是需要引入头文件
  > - 函数不能嵌套定义但是可以嵌套调用

- 形参实参

  > - 形参：形式参数，函数定义时的参数
  > - 实参：实际参数，函数使用时传入函数的参数
  > - \\

- 全局变量

  > - ```c++
  >   #include<cstdio>
  >   #include<cstdlib>
  >   int i = 10;
  >   void print()
  >   {
  >       printf("i am print i =%d\n",i)
  >   }
  >   int main()
  >   {
  >       int i = 5;
  >       printf("i am main %d\n",i);
  >       print();
  >   }
  >   ```
  >
  > - 会提高阅读难度

- setjmp

  > - ```c++
  >   #include<cstdio>
  >   #include<cstdlib>
  >   #include<csetjmp>
  >   // jmp_buf envbuf; //设置中断点
  >   void b(jmp_buf envbuf;)
  >   {
  >       printf("i am func b\n");
  >       longjmp(envbuf,5);
  >   }
  >   void a(jmp_buf envbuf;)
  >   {
  >       printf("before b,i am");
  >       b(envbuf); //通过setjmp跳过下面的语句
  >       printf("finish b,i am");
  >       
  >   }
  >   int main()
  >   {
  >       jmp_buf envbuf;
  >       int ret;
  >       ret = setjmp(envbuf);
  >       if(0==ret)
  >       {
  >           a(envbuf;);
  >       }
  >   }
  >   ```

- 递归调用

  > - ````c++
  >   #include<cstdio>
  >   #include<cstdlib>
  >   
  >   int main()
  >   {
  >       int f(int n);
  >       int n;
  >       while(scanf("%d",&n)!=EOF)
  >       {
  >           //printf("%d!=%d",n,f(n));
  >           //非递归实现
  >           int first = 0;
  >           int second = 1;
  >           int third;
  >           
  >           for(int i=0;i<n;i++)
  >           {
  >               third=first+second;
  >               first=second;
  >               second=third;
  >           }
  >           cout<<third<<endl;
  >       }
  >   }
  >   int f(int n) //斐波那契数列
  >   {
  >       if(n==1) return 1;
  >       if(n==2) return 2;
  >       return f(n-1)+f(n-2);
  >   }
  >   /*
  >   int f(int n)
  >   {
  >       if(0==n)
  >       {
  >           return 1;
  >       }
  >           return n*f(n-1);
  >   }
  >   */
  >   ````
  >
  > - 汉诺塔
  >
  >   - ```c++
  >     #include<cstdio>
  >     #include<cstdlib>
  >     int f(int n);
  >     int main()
  >     {
  >     ```
  >
  >   - 

