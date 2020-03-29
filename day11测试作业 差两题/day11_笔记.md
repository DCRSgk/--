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