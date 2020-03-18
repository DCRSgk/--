## 1 测试一下你的编译器short\int\long\long long数据类型依次占据多大的内存空间

- short	     2位 
- int              4位
- long           4位
- long long  8位

![image-20200317225018734](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200317225018734.png)

```c++
#include<stdio.h>
int main() {
	short i = 3;
	int j = 4;
	long n = 5;
	long long m = 6;
	return 0;
}
```

## 2.int a = -1234, b = 2345，根据a和b的首地址，说出a和b所占据的内存空间各个字节的内存数据

- a和b所占据的内存空间
  - a占据的内存空间：![image-20200317230228142](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200317230228142.png)
    - 由于-1234为负数，计算机通过补码的方式储存负数
    - -1234补码为 1111 \\1111\\1111\\1111\\1111\\1011\\0010\\1110
    - 换算成十六进制每8位组成一个字节的数据为：ff \\ff \\fb\\2e
    - 换成小端储存有：2e\\fb\\ff\\ff 
  - b占据的内存空间：![image-20200317230247118](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200317230247118.png)
    - 由于2345为正数，计算机可以直接用原码储存
    - 2345的源码为 0000\\0000\\0000\0000\0000\\1001\\0010\\1001
    - 换算成十六进制每8位组成一个字节的数据为：00\\00\\09\\29
    - 换成小端储存：29\\09\\00\\00

## **3** 假如一个float类型的数据在内存的布局是(16进制 小端法)66 66 24 41，请计算它的十进制数值

- 将小端法化成大端法方便计算 

  - 66\\66\\24\\41 小端
  - 41\\24\\66\\66 大端

- 根据大端法 每个字节换成8位二进制数据有

  - 0100\\0001\\0010\\0100\\0110\\0110\\0110\\0110

- 去掉第一位的数符（为0说明该浮点数为正数）

  - 1000\\0010 换算成十进制为130 （指数部分为130-127=3）
- 剩下为010\\0100\\0110\\0110\\0110\\0110
  - 实际部分为1.010\\0100\\0110\\0110\\0110\\0110（底数部分）

- 该浮点数为1.01001000110011001100110^3 
- 为：1.0303316066697343373304356785565   //我瞎了真的

## 4.请构造合适的例子编写程序，并且回答下面的问题：

- a如果原来的数据是无符号类型，使用%d打印也是无符号类型吗？

  - 是 代码如下

  - ```c++
    
    ```

  - 

- 

## 8 “helloworld”需要使用多大的字符数组来存储？

- 每个字符一个位置 加上末尾的占位符应该用长度为11的字符数组储存

  - ```
    #include<cstdio>
    int main() {
    	char c[]{ "helloworld" };
    	//我是断点
    	return 0;
    }
    ```

  - ![image-20200317234018301](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200317234018301.png)

## 9 设计程序验证：

-   int类型强制类型转换成short类型，变量（正数、负数）的内存里面会发生什么变化？反过来呢？

  - int强制类型转换成short类型的时候可能会发生溢出

  - ```c++
    #include<cstdio>
    #include<iostream>
    using namespace std;
    int main() {
    	int i = 32768; //short类型的上限值为32767
    	//inti = -32768
    	short j = (short)i;
    	cout << j << endl;
        //我是断点
    	return 0;
    }
    ```

  - ![image-20200318004311954](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200318004311954.png)

  - 在内存中 

    -  int类型：<img src="C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200318004436890.png" alt="image-20200318004436890" style="zoom:33%;" />
    -  short类型：<img src="C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200318004511075.png" alt="image-20200318004511075" style="zoom:33%;" />

  - 反过来则不会溢出 内存中变化如下

    - int类型：<img src="C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200318005058458.png" alt="image-20200318005058458" style="zoom:33%;" />
    - short类型：<img src="C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200318005042509.png" alt="image-20200318005042509" style="zoom:33%;" />

- int类型强制类型转换成float类型，变量（正数、负数）的内存里面会发生什么变化？反过来呢？
  - int类型转换成float类型

