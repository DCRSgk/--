# day01作业笔记

- 1. 打印乘法表 && 打印菱形

     - 在打印图形时候，外层循环控制行，内层循环控制列 

  2. 有序数组的公共部分

     - ```c++
       //思路 新建一个数组 依次遍历
       //找到相等的则填入新数组
       void compare2(int arr1[],int arr2[],int arr3[])
       {
           
           for(int i=0,j=0,k=0;i<8&&j<8;;)
           {
               if(arr1[i]==arr2[j]) ////相等的则填入新数组
               {
                   res[k]=arr1[i]; 
                   ++k;
                   ++i;
                   ++j;
               }
               else if(arr1[i]<arr2[j])
               {
                   ++i;
               }
               else{
                   ++k;
               }
           }
           while(k<8)
           {
               res[k]=0;
               ++k;
           }
       }
       ```

     - 在三个元素时，用第一步的结果来和第三步比较。

     - 在第N个元素的时候，从2开始以依次比较

     - ```c++
       void compareN(int arrN[][8],int res[],int n)
       {
           compar2(arrN[0],arrN[1],res);
           for(int i=2;i<n;++i)
           {N
               compare2(res,arrN[i],res);
           }
       }
       ```

     - 

- day1总结：

  - 打印图形的规律

    - 分行
    - 外层控制行 
    - 内层控制分列
  - 函数复用思想
    - 用前一个函数来计算后一个函数需要的值，可扩展到N（递推思想）

