# day07

### Ep01 复习指针和数组

- ##### 数组

  > - **定义**：实际分配了内存空间
  >
  > - **声明**：通知编译器名字可用
  >
  > - 在数组名做加减运算时：会以元素类型为基类型的指针（加/减一个元素）【对于二维数组来说是直接加一行】
  >
  > - 具有相同数据类型的变量（元素）的集合（数组）
  >
  > - 储存在栈上，在内存中连续存储。
  >
  > - 存储特征
  >
  >   - 不能太大
  >   - 只需知道数组名（首地址）就可以求出整个数组的地址
  >   - 数组名+n（下标）*`sizeof`数据类型
  >
  > - 数组的使用
  >
  >   ![image-20200323094510121](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200323094510121.png)
  >
  > - 数组的传递
  >
  >   > - 对于函数而言，数组的传递是用指针实现的，传入的是数组的首地址（数组名）
  >
  > - 指针数组VS数组指针
  >
  >   - 指针数组=全为指针的 `int *arr[10]` ，每个元素都是指针
  >   - 数组指针=指向数组的指针`int(*p)[10]`，一个指针变量，指向数组。
  >
  > - 二维数组
  >
  >   - ![image-20200323103102700](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200323103102700.png)
  >   - ![image-20200323110525464](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200323110525464.png)
  >   - 二维数组本质为一个一维数组，传递时指针的偏移根据基类型决定

- ##### 字符串

  > - char类型的字符数组 以\\0结尾（内存中的0）
  > - 字符串字面值常量存放在代码段而不是数据段
  > - `scanf("%s",str)`=> 读取以一个单词，遇到空格结束。
  > - ![image-20200323111851398](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200323111851398.png)
  > - ![image-20200323112329593](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200323112329593.png)

### Ep02指针

- ##### 指针滥用

  > - 指针指向的位置不可写（比如存在字符串常量里）
  > - 

- ##### 指针类型

  > - 基于指针指向的变量类型
  > - 指针在使用之前必须初始化 即
  >   - 指针必须指向已经分配的空间

- ##### 指针的传递

  > - 函数调用原理
  >
  > - |       **内核**       |
  >   | :------------------: |
  >   | **栈**（函数储存处） |
  >   |        **堆**        |
  >   |  **数据段&&代码段**  |
  >
  > - 主调函数传递地址给被调函数
  >
  > - 被调函数用解引用来修改结束值
  >
  > - 如果函数传递出来的数据需要修改主函数的值，则应用指针传递数据（传递地址）

### Ep03

- ##### 指针Ⅱ

  > - 在被调函数内要改变原函数的值，则要用指针传递变量
  >
  > - 指针的偏移
  >
  >   - 服务于数组
  >
  >   - 可以通过指针的偏移来访问数组中的元素
  >
  >   - 指针的基类型决定指针偏移的程度
  >
  >   - 将堆指针的加减称之为指针的偏移
  >
  >   - 加就是向后偏移，减就是向前偏移
  >
  >   - ```c++
  >     int main()
  >     {
  >         const int N=5;
  >         int a[N]={1,2,3,4,5};
  >         //数组名储存的是数组的起始地址
  >         int *p;
  >         p=a;   //初始化指针 
  >     		   //此处不需要取地址符
  >         	   //因为数组名=数组首地址=第一个元素的地址
  >     	for(int i=0;i<5;i++)
  >         {
  >             printf("%3d",*(p+i));
  >             //p = &a[4];  //逆序输出
  >             //printf("%3d",*(p-i));
  >         }
  >         printf("\n");
  >         
  >         
  >         
  >     }
  >     
  >     ```
  >
  >   - ```c++
  >     void print(int *p)
  >     {
  >         for(int i=N;i<5;i++)
  >         {
  >             printf("%3d",*(p+i));
  >         }
  >         
  >     }
  >     int main()
  >     {
  >         const int N=5;
  >         int a[N]={1,2,3,4,5};
  >         int *p;
  >         p=a;   //初始化指针 
  >     }		
  >     ```

 - 指针的自增自减运算符

   > - ```c++
   >   int main(){
   >       int a[3]={2,7,8};
   >       int *p;
   >       int j;
   >       p = a;
   >       j=*p++; //j=*p;*p++;
   >       printf("a[0]=%d,j=%d,*p=%d\n",a[0],j.*p);
   >       // 2，2，7
   >       j=(*p)++; //先进行j=*p运算 在对(*p)++ 
   >       printf("a[0]=%d,j=%d,*p=%d\n",a[0],j.*p);
   >       // 2，7，7
   >       
   >   }
   >   ```
   >
   > - 

  >  - 
  >
  >  - ![image-20200323151141576](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200323151141576.png)

- void型指针

  > - 传入时需要强制类型转换成char型

- 动态数组

  > - ```c++
  >   int main()
  >   {
  >       int needSize;
  >       char *pStart;
  >       scanf("%d",&needSize);
  >       pStart=(char*)malloc(needSize);
  >       strcpy(pStart,"Hello");
  >       puts(pStart);
  >       free(pStart);//要把free后的指针置为NULL
  >       pStart=NULL;
  >       
  >   }
  >   ```
  >
  > - ![image-20200323161037397](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200323161037397.png)
  >
  > - 栈空间和堆空间的差异实例
  >
  >   - ```c++
  >     char *printStack()
  >     {
  >         char c[] = "I am printStack";
  >         puts(s);
  >         return c;
  >     }
  >     char *printMalloc
  >     {
  >         char *p=(char*)malloc(20);
  >         strcpy(p,"I am printMalloc");
  >         puts(p);
  >         return p;
  >     }
  >     int main()    
  >     {
  >         char *p;
  >         p=printStack;
  >         put(p);//打印会乱码,
  >                 //函数调用完毕之后会自动释放栈空间
  >         p=printMalloc;
  >         put(p); //打印不会乱码，对于堆来说只要不free都是属于堆的空间。
  >         free(p);
  >         p = NULL;
  >     }
  >     ```

- 用C实现vector

  > ![image-20200323163050492](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200323163050492.png)
  >
  > - ```c++
  >   #include<cstdio>
  >   #include<string>
  >   #define CAPACITY 20
  >   int main()
  >   {
  >       char *p=(char*)malloc(CAPACITY);
  >       char c;
  >       int i=0,cap=CAPACITY;
  >       while(scanf("%c",&c)!EOF)
  >       {
  >           if(i==CAPACITY-1)
  >           {
  >               cap=2*cap;
  >               p=(char*)realloc(p,cap);
  >           }
  >           p[i]=c;
  >           i++;
  >       }
  >       p[i]=0;
  >       puts(p);
  >       free(p);
  >   }
  >   ```
  >
  > - 

- 字符指针&&字符数组初始化

  > - ```c++
  >   int main()
  >   {
  >       char *p='hello';
  >       char c[20]="hello";
  >       c[0]='H';
  >       //p[0]='H';//字符串常量区不可写
  >       p="how are u";
  >       //c="how are u";//因为c是常量
  >   
  >   }
  >   ```
  >
  > - strc



# day08

### Ep01 写在前面

- 代码问题：拿出纸和笔，分析问题，提出解决方案并检查和调整。
- 锻炼自己的调试能力

- 找到问题解决，提问。
- 复习指针和数组
- 二级指针和函数指针
- 讲解习题（103个数找三个有差异的数）

### Ep02 数组指针和二维数组

- 数组指针和二维数组

  > - 定义
  >
  > - ```c++
  >   #include<iostream>
  >   #include<string>
  >   using namespace std;
  >   void print(int p[][4],int row);
  >   int main()
  >   {
  >   	int a[3][4]={1,3,5,7,2,4,6,8,9,11,13,15};
  >       int (*p)[4];
  >       int b[4]={1,2,3,4};
  >       //&b+1=>偏移16个字节的下一个数组 基类型是大小为16个字节的数组
  >       //*(*(a+1)+1) 得到4的办法 偏移两次
  >       //第一次偏移成一个一维数组 第二次再次偏移成一个一维数组中的一个元素
  >     	p=a;  
  >       print(a,3);
  >       /*
  >       p=(int (*)[4]malloc(16*100));
  >       p[99][3]=1000; //动态二维数组
  >       */ 
  >   }
  >   void print(int p[][4],int row)
  >   {
  >       printf("sizeof(p)=%d\n",sizeof(p));
  >       //sizeof只看类型，所以这里p的类型是指针 占4个字节
  >       for(int i=0;i<row;i++)
  >       {
  >          for(int j=0;j<sizeof(*p)/sizeof(int);j++)
  >           {
  >              printf("%3d",*(p[i]+j); //比较容易看懂
  >                  //等价于  *(*p+i)+j     
  >           }
  >           cout<<endl;
  >       }
  >   }
  >   ```
  >
  > - 

### Ep03 指针和数组复习

- 数组

  > - 定义：数据类型+数组名+[数组大小]
  >
  >   - 初始化 = {0}  //自动推导大小：忽略数组大小，根据初始化列表自动推断
  >
  > - 调用数组：数组名+[数组下标]
  >
  >   - 数组下标范围0~数组大小-1
  >   - []的原理：数组指针的偏移 `p[i]`等价于 `*(p+i)`
  >
  > - 数组和指针
  >
  >   - 数组名的数据类型？数值？
  >     - 数组名 = 首个元素的地址 = 数组的地址 = 首地址的指针
  >     - 类型以**元素类型为基类型的指针**
  >     - 不能修改指向但是可以修改指向位置的值：const pointer //指针常量
  >   - e
  >
  > - 二维数组
  >
  >   - 定义：数据类型+数组名+[行] [列]
  >   - 内存分布：同一行连续存储，行与行之间也连续存储，地址连续。
  >     - 按行存储
  >     - 行与行之间也连续存储
  >   - 本质：数组的数组 可以看作是大小为**[行]**的**[列]**个一维数组
  >   - 二维数组数组名的含义：int arr[M] [N]
  >     - arr：基类型是int[N]的指针。
  >     - arr+1 地址值增加了 1 * sizeof（int）*N
  >     - 在函数内：``*arr+1  `    1 * sizeof（int）*N
  >
  > - 字符数组
  >
  >   - 字符串的特点：以\\0结尾的字符数组
  >
  >     - 不会检查数组的大小
  >
  >   - 字符串的使用问题：
  >
  >     - char str[20] ="hello world"
  >
  >     - 使用函数读取的时候：请务必用memset将空间中所有的位置都设置为0；
  >
  >     - 使用memset清空 `char str[30]`
  >
  >       - ```c++
  >         char str[30];
  >         memset(str,0,sizeof(str));
  >         ```
  >
  >       - 一些函数
  >
  >         - strlen.. 表格见笔记
  >
  >       - 大小：什么时候可以用sizeof

- 指针

  > - 概念：存放了已分配空间的地址的一个变量
  > - 定义：基类型 *指针名
  >   - 指针的数据类型由基类型决定
  >   - 解引用、间接访问的空间大小和解释方式
  >     - 解引用：dereferencing the variable 的过程![image-20200329153847053](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200329153847053.png)
  >     - 间接访问：用指针访问变量类型
  > - 指针的偏移：
  >   - 根据指针的基类型的大小进行地址的增加/减少
  >   - 注意指针的偏移和数组之间的联系。
  > - 动态数组
  >   - 分配在堆上
  >   - (基类型*)malloc(数组大小 *sizeof(基类型))
  >   - 申请：p=(基类型*)malloc(数组大小 *sizeof(基类型))
  >     - 不要越界 ：0~（数组大小-1）
  >   - 释放 free（p） ，注意此时P的指向不能偏移
  >   - 注意此时还需将p=NULL 避免野指针。
  >   - 、
  > - 指针的传递
  >   - 在被调函数里修改主函数的值？
  >     - 1. 主调函数将变量的地址传入被调函数（实参= 地址）
  >     - 2. 被调函数用接引用（间接访问）的方式修改变量的值
  >          - 间接访问的方式：* []  ->

### Ep04 二级指针与函数指针

- 二级指针与函数指针

  > - ![image-20200324145304521](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200324145304521.png)
  >
  >   - | 表示形式                              | 含义                                        | 地址值     |
  >     | ------------------------------------- | ------------------------------------------- | ---------- |
  >     | `a`                                   | 二维数组名，指向一维数组a[0]，即0行的首地址 | 0x2000     |
  >     | `a[0]`，`*(a+0)`，`*a`                | 0行0列的元素地址                            | 0x2000     |
  >     | `a+1`，`&a[1]`                        | 1行首地址                                   | 0x2010     |
  >     | `a[1]`，`*(a+1)`                      | 1行0列元素`a [1] [0]`的地址                 | 0x2010     |
  >     | `a[1]+2`，     `*(a+1)+2`，`&a[1][2]` | 1行2列的元素`a[1][2]`                       | 0x2018     |
  >     | `*(a[1]+2)`，`*(a(a+2)+2)`            | 1行2列元素`a[1][2]`的值                     | 元素值为13 |
  >
  >   - 每次偏移+4
  >
  > - 数组指针
  >
  >   - 二维数组可以看成元素为一维数组的数组
  >   - 一维数组的数组名在进行偏移和解引用之后，可以看作是以元素类型为基类型的指针
  >
  > - 如何排序二维数组
  >
  >   - 数组指针
  >     - strcpy/ memcpy
  >   - 二级指针
  >     - 交换指针排序
  >   - 函数指针
  >
  > - 心中要由一幅指针指向的内存图
  >
  > - 常见问题
  >
  >   - ```c++
  >     int a[4][4];
  >     int *p=a;
  >     int *q=a[0];
  >     //p&&q的数据类型一样能够说明a个a[0]一样吗？
  >     //不一样 p++和q++就可以看出区别
  >     int (*p)[4]=a;
  >     
  >     ```
  >
  > - 二级指针
  >
  >   - 定义：基类型为指针类型的指针
  >   - 改变指针的指针
  >   - 二级指针的传递  //晚上重听
  >   - ![image-20200324151119523](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200324151119523.png)
  >   - 改变i的值需要传入i的地址



- 函数指针（概念复杂，使用简单）

  > - 定义：存储函数入口地址的指针
  >
  > - 使用场景：间接引用函数
  >
  > - 功能：传递
  >
  > - ```c++
  >   //定义函数指针
  >   //void (*p)(形参);//这是一个指针，返回值为void。
  >   void b(){
  >       printf("i am ironman \n");
  >   }//返回值是void 无形参
  >   void a(void(*p)(int))
  >   {
  >       p(3);
  >   }
  >   int main(){		//定义的时候要形参
  >       void(*p);	//调用的时候要传递实参
  >       p=b;
  >       //p（2);//使用函数指针间接访问b函数
  >       a(p);
  >   }//函数名单独使用，就是函数指针
  >   ```
  >
  > - 
  >
  > - 函数指针的实际使用场景
  >
  >   - 集中某个地址
  >   - 元素为指针的数组
  >   - 对某商品进行排序的时候 交换指针比交换结构体简单
  >   - 



- 使用指针数组排序字符串

  > - ```c++
  >   char b[5][10]={"lele","lili","lilei","hanmeimei","zhousi"};
  >   char* p[5];
  >   for (int i=0;i<5;i++)
  >   {
  >       p[i]=b[i];//对于二维数组的列下标来说 一个列下标表示一行，每行的开头元素就是基类型为一整行的指针。
  >   }
  >   //排序p用冒泡排序
  >   char **p2 = p;
  >   for(int i=4;i>=1;--i)
  >   {
  >       for(int j=0;j<i;++j)
  >       {
  >           if(strcmp(p2[j],p2[j+1]))
  >           {
  >               char *tmp=p2[j];
  >               p2[j]=p2[j+1];
  >               p2[j+1]=tmp; //交换
  >           }
  >       }
  >       print(p2);
  >       puts("------------------");
  >       for(int i=0;i<=4;i++)
  >       {
  >           puts(b[i]);
  >       }
  >   } 
  >   ```

- 二维数组VS二级指针

  > - 在默认的情况下二者没有联系
  >
  > - ```c++
  >   int a[4][3];
  >   /*
  >   a => 数组名 /指向数组的指针
  >   a[0] => int[3]/int*
  >   a[0][1] => int
  >   //二维数组的解引用流程不涉及二级指针
  >   */
  >   
  >   ```
  >
  > - 

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

# day10



### Ep01

- 局部变量和全局变量

  >  ```c++
  >  //int k=10; //需要放到函数之上 全局变量
  >  void print()
  >  {
  >  printf("K=%d",k)
  >  } //此时无法打印K 未声明的标识符
  >  int k=10;
  >  int main ()
  >  {
  >  int i=10
  >  {
  >     int j=5; //变量在离自己最近的大括号内有效
  >  }
  >  printf("j=%d",j);// 未声明的标识符
  >  }
  >  ```
  >
  >  - 全局变量从开始到结束都占用储存空间
  >  - 太多的全局变量容易出错
  >  - 全局变量放在数据段
  >  - 全局变量只能初始化一次
  >  - 借用全局变量的需要加`extern`
  >  - 局部变量有效范围在最近的`{}`之间

- 静态和动态存储方式

  > - 常用变量就是动态变量
  >
  > - 静态存储在静态区
  >
  > - 仅初始化一次
  >
  > - 静态局部变量是在编译时赋初值的，即只赋初值一次
  >
  > - 用static修饰全局变量，那么该全局变量将不能被其他文件引用
  >
  > - 用static 修饰函数，那么该函数将不能被其他文件引用。
  >
  >   ```
  >   void print()
  >   {
  >   	static int i=0;
  >   	i++;
  >   	printf("i am print%d",i)
  >   }
  >   ```

### Ep02

- 结构体

  > - ```c++
  >   //为了避免浪费空间，在定义结构体的时候要将小字节的放到一起
  >   struct student_t{
  >       int num;
  >       char name[20];
  >       char sex;
  >       int age;
  >       float score;
  >       char addr[30];
  >       
  >   };
  >   int main()
  >   {    //构造数据类型 
  >       struct student_t s= {1001,"aki",'M',20,98.5,"shanghai"};
  >       struct student_t sArr[3];
  >       printf("%d %s %c %d % 5.2f %s \n",s.num,s.sex,s.age,s.score,s.addr);
  >       for(int i=0;i<3;i++)
  >       {
  >           scanf_s("%d %s %c %d %f %s"&sArr[i].num,sArr[i].name,&sArr[i].age,&sArr[i].score,sArr[i].addr)
  >       } //输入
  >        for(int i=0;i<3;i++)
  >       {
  >            printf ("%d %10s %c %d %f %s"sArr[i].num,sArr[i].name,sArr[i].age,sArr[i].score,sArr[i].addr)； 
  >       //输出
  >        }
  >       
  >           
  >       
  >   }
  >   ```
  >
  > - 结构体指针
  >
  >   - 一个结构体变量的指针就是该变量所占据的内存段的起始地址。可以设一个指针变量，用来指向一个结构体变量，此时该指针变量的值是结构体变量的起始地址。
  >
  >   - ```c++
  >     typedef struct student{
  >         int num;
  >        	char name[20];
  >         float score;
  >     }student_s，*pstudent_s;
  >     //等价于 pstudent_s struct student*
  >     int maim()
  >     {
  >         int num;
  >         student_s s={1001,"wwe",95.5};
  >         student_s sArr[3]={1001,"wwe",95.5,1002,"apex",85.5,1003,"ooc",75.5}
  >         pstudent_s p;
  >         p=&s;
  >         pritnf("%d %s %f\n",(*p).num,(*p).name,(*p).score);
  >         //间接访问
  >         num=p->num++; //num=p->num  p->num+=1
  >         cout<<num<<" "<<p->num;
  >         // 1001  1002 
  >         num=p++->num; //提出++ 先num=p->num 再++p 
  >         cout<<num<<" "<<p->num;
  >         // 1001 1005
  >     }
  >     ```

- 链表

  > - 顺序存储
  >
  >   - 物理连续&&逻辑连续
  >
  > - 链式存储
  >
  >   - 逻辑连续不一定物理连续
  >
  > - ```c++
  >   struct student{
  >      
  >   }
  >   ```
  >
  > - 增删查改：//晚上重新听 头插法
  >
  > - ![image-20200326115116240](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200326115116240.png)
  >
  > - 
  >
  > - ![image-20200326115816521](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200326115816521.png)
  >
  > - ```c++
  >   int main()
  >   {
  >       pStuent_t phead=NULL,ptail=NULL;
  >       whlie(scanf("%d"，&num)!=EOF){
  >           listHead
  >       }
  >   }
  >   ```
  >
  > - 

![image-20200326144259535](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200326144259535.png)

![image-20200326145643952](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200326145643952.png)

- 顺序插入

  ![image-20200326150036070](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200326150036070.png)

- 



### Ep03 复习

- 函数

- 结构体

  > - 声明 ：struct+结构体名{ 成员列表}；
  >
  > - 定义结构体变量
  >
  >   - struct+结构体名{ 成员列表}；
  >   - 初始化列表
  >   - `sizeof`：不是简单相加，而要考虑对齐类型（一般为4字节对齐）
  >
  > - 访问成员：`.`运算符比`*`高
  >
  >   - 结构体名字可以和变量名相同
  >   - 支持取地址`&`和赋值`=`
  >
  > - 结构体数组
  >
  >   - 没啥差别
  >
  > - 结构体指针
  >
  >   - 访问成员时使用箭头`->`
  >   - 解引用需要加·`()`
  >
  > - typedef：给类型取别名
  >
  > - 链表
  >
  >   - 结点定义
  >
  >     - ```c++
  >       sruct node{
  >           int data;
  >           struct node* pNext;
  >       };
  >       ```
  >
  >     - 
  >
  >   - 头插法
  >
  >     - ```c++
  >       if(){  
  >       
  >       }//判空  为空则插入第一个节点
  >       else{
  >           
  >           p.tail->p.next;
  >           
  >       }//若非空先链接新节点之后头指针前移
  >       ```
  >
  >     - 
  >
  >   - 尾插法
  >
  >     - ```c++
  >       if(){  
  >       
  >       }//判空  为空则插入第一个节点
  >       else{ 
  >           
  >           p.tail->p.next;
  >           
  >       }//若非空先链接新节点之后尾指针后移
  >       ```
  >
  >     - 
  >
  >   - 有序插入
  >
  >     - ```c++
  >       //使用两个指针，找到合适位置和之前位置
  >       if(){  
  >       
  >       }//判空  为空则插入第一个节点
  >       if else{ 
  >           whlie(){}  //找到合适位置和之前位置
  >           p.tail->p.next;
  >       }
  >       else{}
  >       //若非空先链接新节点之后尾指针后移
  >       ```
  >
  >     - 

# day11

### Ep01 写在前面

- 函数

  > - 递归函数：调用自身的函数
  > - 变量以及作用域
  >   - static 变量：仅初始化一次，只在本文件内使用。

- 链表

  > - 头插法，
  >   - 新建节点，插入的值进行初始化
  >   - 判空，如果为空，则新节点赋值给头尾指针
  >   - 若不为空，新节点的Next值指向原有头节点
  >   - 新节点成为新的头节点（头指针）
  > - 尾插法
  >   - 新建节点，插入的值进行初始化
  >   - 判空，如果为空，则新节点赋值给头尾指针
  >   - 若不为空，新节点的Next值指向原有尾节点
  >   - 新节点成为新的尾节点（尾指针）
  > - 有序插入
  >   - 新建节点，插入的值进行初始化
  >   - 判空，如果为空，则新节点赋值给头尾指针
  >   - 若不为空
  >   - 如果新节点的值小于头指针，则直接头插法
  >   - 如果大于头指针，则遍历链表
  >   - 找到比插入值大的节点位置，进行头插法
  >   - 如果遍历链表未找到
  >   - 则直接尾插法

### Ep02 链表的删除

- ![image-20200327102529719](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200327102529719.png)

![image-20200327102738712](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200327102738712.png)

### Ep03 链表的修改

见 代码

### Ep04 联合体和枚举

- 联合体 

- ```c++
  union data{
      int i;
      char c;
      float f;
  }
  typedef struct student {
  	int num; //学号
  	float cham;
  }Student_t, * pStudent_t;
  int main()
  {
      union data a; //
      student_t s;
      a.i=10;
      a.c='A';
      a.f=98.5;
      //此时 a.i/a.c/a.f都用一个地址
      //一个时间内只有一个成员有效
      s.num=1001;
      s.cham=1024;
      //此时二者独立，占不同地址
  }
  ```

- 枚举

  > - ```c++
  >   enum weekday{sun,mon,tue,wed,thu,fri,sat};
  >   int main()
  >   {
  >       enum weekday workday; 
  >       workday=1;
  >       printf("wed=%d\n",workda);
  >       
  >   }
  >   ```

### Ep05 常用数据结构和算法

- 算法的目的是为了提高存取效率
- 常用栈，队列，二叉树，堆，红黑树，哈希表等数据结构的增删改查
- 通过排序算法掌握时间复杂度与空间复杂度
- 掌握常用查找算法
- 算法学习方法讲解
- 在一开始设计好函数的目的是很重要的

### Ep06 栈 stack

- 栈 数据结构的笔记见vs //之后贴出

  > - 后进先出
  > - 可以用数组实现，也可以用链表实现
  > - ![image-20200327112036186](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200327112036186.png)
  > - ![image-20200327114403249](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200327114403249.png)

![image-20200327115451513](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200327115451513.png)。

### Ep06队列

- 

### Ep07二叉树

- ![image-20200327143551304](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200327143551304.png)
- ![image-20200327143641430](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200327143641430.png)
- BFS
- 堆排
- 度：有几层即度为几
- k层的二叉树最多有2^(k-1)个节点
- 深度为k，有2^(k-1)个节点的二叉树叫满二叉树
- 完全二叉树
  - 仅允许最后一层有空节点且空缺在右边
  - 对任意结点，如果其右子树的深度为j，则其左子树的深度必为j或j+1。度为1 的点只有1个或0个

![image-20200327144343938](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200327144343938.png)

- 如何正确的分析前序遍历

  > - 根+左+右的顺序输出
  > - ![image-20200327145745405](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200327145745405.png)
  > - ABD HIE  JCFG 

- 中序遍历

  > - HDIBJEAFCG  ~~将上图一脚踩扁 按照顺序输出~~
  > - 

![image-20200327151616238](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200327151616238.png)

![image-20200327152858907](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200327152858907.png)

# day12

### Ep01

- 最坏时间复杂度T(n)
- 时间复杂度：执行次数了，忽略常数。
- 为什么要学算法：处理较多数据时效率高

### Ep02

- 

