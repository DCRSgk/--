# 测试作业：

### 从（0，0）开始到（m，n），有多少种路径走到（m，n）

- 排列组合问题，可以看作是从m+n种选n种向右走/或者选m种向下走

- C（m+n，n）||C（m+n，m）

- 先写一个求阶乘的函数

- 数学方法

  - ```c++
    #include<iostream>
    #include<cstdio>
    using namespace std;
    int Factorial(int n);
    int main()
    {
    	int m, n;
    	int path;
    	scanf_s("%d %d", &m, &n);
    	path = Factorial(m + n) / (Factorial(m) * Factorial(m + n - m));
    	printf("走到（%d，%d），有%d种方法\n", m, n, path);
    }
    int Factorial(int n)
    {
    	long long m = 1;
    	for(int i=1;i<=n;i++)
    	{
    		m *= i;
    	}
    	return m;
    }
    ```

  - ![image-20200325192837652](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200325192837652.png)

- 递归方法

  - 思路：
  
    - 
  
  - ```c++
    #include<iostream>
    #include<cstdio>
    using namespace std;4
    int Factorial(int n);
    int main()
    {
        
    ```
  
  - 

