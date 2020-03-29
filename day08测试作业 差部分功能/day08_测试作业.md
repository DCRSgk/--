# 测试作业

### 1 利用数组，实现大整数加法（要考虑正负数的情况）

- 实在想不出加上正负怎么判断，所以写了个没考虑正负的。

- ```c++
  #include<iostream>
  #include<cstdio>
  #include<string>
  using namespace std;
  constexpr auto N = 1024;
  void bigadd(char num1[],int num1_size, char num2[],int num2_size);
  int main()
  {
  	int num1_size, num2_size;
  	char num1[N];
  	char num2[N];
  	cin >> num1;
  	cin >> num2;
  	num1_size = strlen(num1);
  	num2_size = strlen(num1);
  	bigadd(num1, num1_size, num2, num2_size);
  }
  void bigadd(char num1[], int num1_size, char num2[], int num2_size)
  {
  	int num1_in[N];
  	int num2_in[N];
  	int num = '0', i, k, j, tmp;
  	for (int i = num1_size - 1, j = 0; i >= 0; i--) // char的最后一位是\n
  	{
  		num1_in[j++] = num1[i] - '0';
  	}
  	for (int i = num2_size - 1, j = 0; i >= 0; i--)
  	{    //倒序输入并转换
  		num2_in[j++] = num1[i] - '0';
  	}
  	int Sum_size = num1_size > num2_size ? num1_size : num2_size;
  	for (int i = 0; i <= Sum_size; i++) 
  	{
  		num1_in[i] += num2_in[i];
  		if (num1_in[i] >= 10)    //进位
  		{
  			num1_in[i + 1] += 1;
  			num1_in[i] -= 10;
  		}
  	}
  	int i;
  	for (i = Sum_size - 1; i >= 0; i--)
  	{
  		if (i > 0)
  			for (; i >= 0; i--)
  			{
  				cout << num1_in[i];
  			}
  		else
  		{
  			cout << 0;
  		}
  		cout << endl;
  	}
  }
  ```

- 

### 2 使用数组指针和二级指针分别实现字符串数组的排序

- 数组指针

  - ```c++
    #include<iostream>
    #include<cstdio>
    #include<string>
    using namespace std;
    int main() 
    {
    	char b[5][10] = { "lele","lili","lilei","hanmeimei","hhh" };
        char(*p)[10]= b;             //定义一个指针指向数组b的每一行
        char temp[10];
        for(int i=0;i<=4;i++)
        {
            if (strcmp(p[i], p[i + 1]) ) //由于p[ ]是一个数组，无法直接赋值。所以需要用到strcpy
            {
                strcpy(temp, p[i]);
                strcpy(p[i], p[i + 1]);
                strcpy(p[i + 1], temp);
            }
            cout << p[i] << endl;
        }
    }
    ```

  - 

- 二级指针

  - ```c++
    #include<iostream>
    #include<cstdio>
    #include<string>
    using namespace std;
    int main() 
    {
    	char b[5][10] = { "lele","lili","lilei","hanmeimei","hhh" };
    	char* p[5];             //定义一个长度为5的指针数组
    	for (int i = 0; i < 5; i++)
    	{
    		p[i] = b[i];
    	}
        char** p2 = p;    //二级指针p 指向指针数组
    	for (int i = 4; i >= 0; i--)
    	{
    		for (int j = 0; j < i; j++)
    		{
    			if (strcmp(p2[j], p2[j + 1])) 
    			{
    				char* tmp = p2[j];
    				p2[j] = p2[j + 1];
    				p2[j + 1] = tmp;
    			}
    		}
    	}
        for(int i=0;i<=4;i++)
        {
            cout << p[i] << endl;
        }
    }
    ```

  - 

