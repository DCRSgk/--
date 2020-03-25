# 提高作业

### 有四题不太会 打印这种图型这种题都很难绕过来

### 1 输入年月日，输出该日期是当年的第几天

```c++
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int every_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int year, month, day;
	int date_sum =0;
	scanf_s("%d %d %d", &year, &month, &day);
	if (month > 1) {
		for (int i = 0; i < month - 1; i++) {
			date_sum += every_month[i];
		}
		date_sum += (year % 4 == 0 && year % 100 == 0 || year % 400 == 0);
		date_sum += day;
	}
	else {
		date_sum += day;
	}
	cout <<"今天是"<<year<<"的第"<< date_sum <<"天"<< endl;
	return 0;
}
```

![image-20200319195421701](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200319195421701.png)

### 2 求任意两个日期相差的天数

- ```c++
  #include<iostream>  //写了个函数求当前日期到公元0年1月1号是多少天
  #include<cstdio>	//二者想减加上年份的闰年就是相差多少天
  #include<cmath>		//如果年相差4年以上则判断期间是否有闰年 
  using namespace std;//4和400均为闰年 加1天
  int date_sum(int year, int month, int day);
  int main() {
  	int year1, month1, day1;
  	int year2, month2, day2;
  	int date_total =0;
  	int smaller_year;
  	scanf_s("%d %d %d", &year1, &month1, &day1);
  	scanf_s("%d %d %d", &year2, &month2, &day2);
  	if (abs(year1 - year2) > 4) { //年数判断 
  		smaller_year = year1 < year2 ? year1 : year2;
  		for (int i = smaller_year; i >= abs(year1 - year2); i++) {
  			date_total += (i % 4 == 0 && i % 100 || i % 400);
  		}
  		date_total = abs(date_sum(year1, month1, day1) - date_sum(year2, month2, day2));
  	}
  	else if ((abs(year1 - year2) < 4) &&  //四年以内出现跨闰年的情况 则直接+1
  		((year1 % 4 == 0 && year1 % 100 || year1 % 400) || 
  		(year2 % 4 == 0 && year2 % 100 || year2 % 400)) ){
  		date_total = abs(date_sum(year1, month1, day1) - date_sum(year2, month2, day2)) + 1;
  	}
  	else {
  		date_total = abs(date_sum(year1, month1, day1) - date_sum(year2, month2, day2));
  	}
  	cout << "两日期相差" << date_total << "天";
  	return 0;
  }
  int date_sum(int year, int month, int day) {      //和公元元年1月1日相差多少天
  	int every_month[] ={31,28,31,30,31,30,31,31,30,31,30,31 };
  	int date_sum = 0; 
  		if (month > 1) {
  			for (int i = 0; i < month - 1; i++) {
  				date_sum += every_month[i];
  			}
  			date_sum += (year % 4 == 0 && year % 100 == 0 || year % 400 == 0);
  			date_sum += day;
  		}
  		else {
  			date_sum += day;
  		}
  	date_sum += 365 * year - 1;
  	return date_sum;
  }
  ```

- 

![image-20200319212410640](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200319212410640.png)

### 3 输入年月日，输出该日期是星期几

- ```c++
  #include<iostream>  //写了个函数求当前日期到公元0年1月1号是多少天
  #include<cstdio>	//将天数和7取余 得到是几就可以反推出当天是星期几
  #include<cmath>		// 公元1月1号，因为教皇格里戈八世抹去的10天 按照计算机的推理是周一
  int date_sum(int year, int month, int day);
  int main() {
  	int year, month, day;
  	int date_total;
  	int i;
  	scanf_s("%d %d %d", &year, &month, &day);
  	date_total = date_sum(year, month, day)-1;
  	switch (date_total % 7){
  	case 0:printf("%d年%月%日是星期一", year, month, day); break;
  	case 1:printf("%d年%月%日是星期二", year, month, day); break;
  	case 2:printf("%d年%月%日是星期三", year, month, day); break;
  	case 3:printf("%d年%月%日是星期四", year, month, day); break;
  	case 4:printf("%d年%月%日是星期五", year, month, day); break;
  	case 5:printf("%d年%月%日是星期六", year, month, day); break;
  	case 6:printf("%d年%月%日是星期天", year, month, day); break;
  	}
  	return 0;
  }
  int date_sum(int year, int month, int day) {      //和公元元年1月1日相差多少天
  	int every_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
  	int date_sum = 0;
  	if (month > 1) {
  		for (int i = 0; i < month - 1; i++) {
  			date_sum += every_month[i];
  		}
  		date_sum += (year % 4 == 0 && year % 100 == 0 || year % 400 == 0);
  		date_sum += day;
  	}
  	else {
  		date_sum += day;
  	}
  	date_sum += 365 * year - 1;
  	return date_sum;
  
  }
  ```

- 

- ![image-20200319215811221](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200319215811221.png)

4 输入日期，输出经过n天以后的日期和星期

5 输入年月，输出该月的日历

6 输入年，输出一整年的日历

### 7 按要求找数

##### a 现在有101个整数，其中有50对两两相同的数，一个与其他数互不相同的数（比如1，1，2，2，3，3，5 其中5就是这个独特的数），求出这个数

- ```c++
  #include<iostream>
  #include<cstdio> //遍历并异或 得到重复的数字
  using namespace std;
  int main() {
  	int a[7] = { 1,1,2,2,3,3,5 };
  	int result = 0;
  	for (int i = 0; i < 7; i++) {
  		result = result ^ a[i];
  	}
  	cout << result;
  	return 0;
  }
  ```

- ![image-20200319225324399](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200319225324399.png)



##### b现在有102个整数，其中有50对两两相同的数，两个与其他数互不相同的数，求出这两个数

- ```c++
  #include<iostream>   //听了三遍龙哥讲的按位与和异或和做题思路
  #include<cstdio>     //遍历并异或 排除两两重复的数字
  using namespace std; //剩下两个全在一个result里 需要再次遍历数组区分开
  int main() {	     //遍历前需要对进行按位与运算 （取其中一个数）
  	int a[] = { 1,1,2,2,3,3,4,4,5,5,6,7};
  	int result = 0;
  	int left = 0;
  	int right = 0;
  	for (int i = 0; i < 12; i++) {
  		result = result^ a[i];
  	}
  	result = result & (-result); 
  	for (int i = 0; i < 12; i++) { //再次遍历
  		if (a[i] & result) { //左边一堆
  			left = left ^ a[i];
  		}
  		else {
  			right = right ^ a[i];
  		}
  	}
  	cout << left << endl;
  	cout << right << endl;
  	return 0;
  }
  ```

- ![image-20200320002445401](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200320002445401.png)



c 现在有103个整数，其中有50对两两相同的数，三个与其他数互不相同的数，求出这三个数（注意测试独特数为 3，5，6的情况）