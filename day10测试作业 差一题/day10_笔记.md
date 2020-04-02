# day10

### Ep01

- 局部变量和全局变量

  >  ```c++
  >  //int k=10; //需要放到函数之上 全局变量
  >  void print()
  >  {
  >   printf("K=%d",k)
  >  } //此时无法打印K 未声明的标识符
  >  int k=10;
  >  int main ()
  >  {
  >   int i=10
  >   {
  >       int j=5; //变量在离自己最近的大括号内有效
  >   }
  >   printf("j=%d",j);// 未声明的标识符
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
  > - ![image-20200326115116240](../assess/image-20200326115116240.png)
  >
  > - 
  >
  > - ![image-20200326115816521](../assess/image-20200326115816521.png)
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

![image-20200326144259535](../assess/image-20200326144259535.png)

![image-20200326145643952](../assess/image-20200326145643952.png)

- 顺序插入

  ![image-20200326150036070](../assess/image-20200326150036070.png)

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



