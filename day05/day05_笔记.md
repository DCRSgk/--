# day05

### Ep01 预习

- C是面向内存的语言

- 数据类型（深入）

  > - 计算机构成
  >
  >   > - 内存
  >   >
  >   > - |      **内核**      |
  >   >   | :----------------: |
  >   >   |   **栈**（函数）   |
  >   >   | **堆**（动态申请） |
  >   >   |     **数据段**     |
  >   >   |     **代码段**     |
  >   >
  >   >   
  >
  > - 数据类型的实质
  >
  >   > - 内存空间有多大
  >   >
  >   > - 如何解释这段内存中的0/1
  >   >
  >   > - e.g.： 同一份内存空间同解释
  >   >
  >   >   - int类型
  >   >
  >   >   - 占4个字节（32位） 
  >   >
  >   >   - 用补码存储负数
  >   >
  >   >     
  >   >
  >   >   - unsigned int
  >   >
  >   >   - 占4个字节（32位） 
  >   >
  >   >   - 用原码储存（只有正数）
  >   >
  >   >   - ```c++
  >   >     usgigned int u = 0xffffffff
  >   >     printf("unsigned int = %u, int = %d\n",u,u);
  >   >     //结果为 unsigned int = 4294697295 , int = -1
  >   >     ```
  >   >
  >   > - 

- 运算符

- 条件结构、

- 循环 （while&&do-while&&for&&goto）

  - 理解
  - whlie循环的含义：先满足条件就执行
  - do-while 先执行，再进行判断

- 数组

  - 连续存放相同数据类型的定长集合
  - 申请数组时，分配空间在栈里（~~容易溢出~~）

- 数组的一些问题

  - 在C里不检查数组越界
  - 拷贝时候只拷贝首地址（数组指针）
  - 数组的数组
    - 二维数组![image-20200320102623026](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200320102623026.png)

### Ep02 循环

-  while 

  - 死循环 

  > - while循环内没有使条件趋近于假的语句
  > - 不能在while循环后加分号

- do-while

  > - 先进行循环体，再进行判断
  > - 一定要在while循环后加分号

- for

  > - for(表达式1；表达式2；表达式3)
  >   - 先计算1
  >   - 后判断2 为真则执行循环
  >   - 再计算表达式3
  >
  > - 所有语句都可省略 但是要在循环体内加上判断语句和递增语句
  >
  > - for括号后面加分号，会造成计算错误
  >
  >   //continue 本次循环，

- continue

  > - 需要跳过某条件时 
  >   - 跳出**当次循环**1
  >   - continue后面的语句本次循环不再执行
  > - 当continue使用于while和do while循环时，注意不要跳过让循环趋近于假的语句。

### Ep03 数组（重点）

- 一维数组的内存原理及使用

  > - 定义和使用
  >
  >   - 需要先初始化
  >
  >   - 有相同数据类型
  >   - 定长
  >   - C中无动态数组
  >   - 不能用变量定义数组大小
  >   - 数组下标从0开始
  >
  > - ```c++
  >   #define N 5
  >   int main ()
  >   int arr[N]={1,2,3,4,5};//4*5个字节
  >   //在内存当中连续储存
  >   ```
  >
  > - 访问越界
  >
  >   - stack around arr  栈使用访问越界
  >   - stack over flow  栈溢出
  >
  > - scanf和字符数组
  >
  >   - scanf 不能够检测字符数组输入长度 容易造成访问越界
  >
  > - 函数和数组
  >
  >   - 在传入数组的值的时候，不能同时传入数组长度 //本质是传指针进去。
  >   - 相当于函数也调用了原来的内存空间

- 二维数组的原理及使用

  > - 数组【a】【b】
  >
  > - 数组的数组  sizeof之后为为a*b
  >
  > - <img src="C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200320144921865.png" alt="image-20200320144921865" style="zoom:50%;" />
  >
  > - 内存中也行线性储存的
  >
  > - ```c++
  >   int main() .
  >   int a[3][4]={1,3,5,7,2,4,6,8,9, 11, 1
  >   int b[4]={1,2,3, 4};
  >   int c[3][4]={{1}, {5, 9}};//可只对部分元素初始化
  >   printf(" a[2] [3]=%d\n", a[2][3]);
  >   return 0;
  >   }
  >   
  >   ```
  >
  > - 数组指针：
  >
  >   ![image-20200320145818227](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200320145818227.png)

- 字符数组使用方法

  > - 存储字符串
  >
  > - ![image-20200320155822363](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200320155822363.png)
  >
  > - scanf 读入的时候 
  >
  >   - 不需要取地址符（数组名就是数组的地址，不需要取地址的地址）
  >   - %s时 空格结束
  >
  > - gets和puts //容易访问越界
  >
  >   - 类似于C++的getline？
  >
  >   - ```c++
  >     int main(){
  >     	char c[50];
  >         get(c); //全按照字符型读入
  >         printf("%s\n",c); //等价于puts（c）
  >     }
  >     
  >     ```
  >
  >   - ```c++
  >     //连续读入字符串
  >     int main(){
  >     	char c[50];
  >         whlie(get(c)!=NULL){
  >             puts(c);
  >         }
  >         printf("%s\n",c); //等价于puts（c）
  >     }
  >     ```
  >
  > - fgets //会将 \n强制存进数组
  >
  >   - fgets（字符数组名,长度,stdin）
  >
  >   - ```c++
  >     int main(){
  >     	char c[50];
  >         fgets(C,sizeof(c),stdin)
  >         printf("%s\n",c); //等价于puts（c）
  >     }
  >     
  >     ```
  >
  >   - 

- str等字符串系列函数的使用

  > - ![image-20200320162426812](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200320162426812.png)
  >
  > - srtlen( ) //求长度
  >
  >   - ```c++
  >     int main(){
  >         char c[50];
  >         size_t len;
  >         while(fgets(c,sizeof(c),stdin)!=NULL){
  >         c[strlen(c)-1]=0;
  >         put(c);
  >         len = strlen(c);
  >         printf("%d\n",len);
  >         }
  >     }
  >     ```
  >
  > - strcopy（） 复制函数
  >
  >   - strcopy（目标，模板）； 模板  => 目标
  >   - 允许带空格的复制=，

