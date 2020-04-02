# day13

### Ep01 写在前面

- 链表的删除

  > - 判断链表是否为空 
  > - 判断是否是头节点
  >   - 如果是则直接将头节点的pNext赋值给头节 之后free
  >   - 如果删除结点后链表为空，设置尾指针为NULL
  > - 若不为头节点
  >   - 遍历链表，找到删除值后将前一个节点的pNext指针指向删除节点的下一个节点（pNext）
  >   - 判断删除结点地址值是否等于尾指针，如果相等，则说明删除的为尾节点，将尾指针指向前一个节点。（pPre）
  > - 若没有删除的值则打印没有发现删除节点的值

- 栈和队列

- 二叉树的层次建树 辅助队列

- 插入排序

  > - 认为0号元素自然有序，从一号元素开始插入
  > - 存储插入元素的值，从后往前依次拿有序序列元素值与插入元素值进行比较
  > - 如果有序序列大于插入元素值，则有序序列值后移一位，找到插入元素的位置
  > - 将插入元素值放入对应位置

- 快速排序

  > - 任意一个元素作为分割值（最后/第一个），将比分隔值小的放在分隔值的左边，大的放在右边，分分割值的位置确定，返回分隔值的下标。
  > - 将数组一分为二，前半部分继续分割，后半部分亦然，循环往复实现有序。

- 作业：学生

  ```c++
  typedef struct
  {
      int num
      char name[20];
  	float chinese;
  	float math;	
  	float eng;
  }student_t;
  int main()
  {
      student_t sArr[5];
      for(int i=0;i<5;i++)
      {
  scanf("%d%s%f%f%f",&sArr[i].num,sArr[i].name,&sArr[i].chinese,&sArr[i].math,&sArr[i].eng);
      }
      qsort (sArr,N,sizeof(Student_t), compareNum);
       for(int i=0;i<5;i++)
      {
           pritnf("%d %15s %5.2f,%5.2f,%5.2f %6.2f",sArr[i].num,sArr[i].name,sArr[i].chinese,sArr[i].math,sArr[i].eng,sArr[i].chinese+sArr[i].math+sArr[i].eng);
  
  }
  int compareNum(const void*pleft,const void*pright)
  {
      pstudent_t p1=(pstudent_t)pleft;
      pstudent_t p2=(pstudent_t)pright;
      return p1->num-p2->num;
      
  }
      int compareScore(const void*pleft,const void*pright)
  {
      pstudent_t p1=(pstudent_t)pleft;
      pstudent_t p2=(pstudent_t)pright;
      if(score....)
          return 1;
          else if
          {
              return -1;
          }
          else
          {
              return 0;
          }              
  }
  ```

  

### Ep 02 堆排序

- 堆heap

  > - 按层次建树的顺序的数组（必须是完全二叉树）
  > - 大根堆小根堆
  >   - 大根堆
  >     - 
  >   - 小根堆
  > - 堆排序的实现
  >   - 建堆过程：
  >   - 拿到最后一个父亲节点
  >   - 拿父亲节点和左右孩子中较大的比较
  >   - 如果发现小于孩子节点就进行交换，如果发生交换，则将发生交换的孩子节点作为新的父亲，依次重复进行，直到根节点。把堆调整为大根堆
  >   - 交换零号元素与数组最后-一个元素，然后将剩余元素重新调整为大根堆，循环往复，最后数组有序

- 调试原因

  > 1、指针偏移
  > 2、前面访问越界

- 稳定性

  > - 排序时候出现局部最优/原地tp
  > - 即交换的时候出现

- 计数排序

  > - 需要额外的数组储存排序的数值变换范围，该数组所有元素初始化为0。
  > - 遍历数组获取对应值后，将技术数组对应下标位置值+1，遍历完毕就得到数组中所有值出现的情况。
  > - 外层控制数值变化，内层将计数数组中对应数值出现的次数，依次填入原有数组

- n个无序数数组，让找出第K大的数

  > - 建立k个元素的小根堆，那么就可以拿顶部元素和n-k个元素依次比较。

- 去除重复元素  

  > - 位图 500m空间 一位一个数
  >
  > - 需要磁盘辅助存储  外部排序：建小根堆
  >
  > - 两台电脑找k（删除法） 假设每次找到的k\2部分第一次都比第二次大
  >
  >   - |   第一次    | 第二次  | 第三次 |
  >     | :---------: | :-----: | :----: |
  >     | n\2 找到k\2 | n\2 找  |        |
  >     | n\2 找到k\2 | n\2-k\2 |        |
  >     |             |         |        |
  >
  >     