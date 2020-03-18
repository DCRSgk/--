##  打印九九乘法表

```c++
//由于不懂是哪个版本的所以我都写了 
#include<stdio.h>
int main() {
	//正常版本
	for (int i = 1; i <= 9; i++) {        //控制行
		for (int j = 1; j <= 9; j++) {      //控制列
			if (j == 1) {
				printf("%d*%d=%2d", j, i, i * j);
			}
			else {
				printf("%2d*%d=%2d", i, j, i * j);
			}	
		}
		printf("\n");
	}
	//倒三角版本
	//for (int i = 1; i <= 9; i++) {    //控制行
	//	for (int j = 9; j >= i; j--) {//控制列
	//		if (j == 9) {
	//			printf("%d*%d=%d", (10 - j),  i , i * (10 - j));
	//		}
	//		else {
	//			printf("%2d*%d=%d", (10 - j), i, i * (10 - j));
	//		}
	//	}
	//	printf("\n");
	//}
	//正三角版本
	//for (int i = 1; i <= 9; i++) {    //控制行
	//	for (int j = 1; j <= i; j++) { //控制列
	//		if (j == 1) {
	//			printf("%d*%d=%2d", j, i, i * j);
	//		}
	//		else {
	//			printf("%2d*%d=%2d", j, i, i * j);
	//		}
	//	}
	//	printf("\n");
	//}
	return 0;
}
```

![image-20200317205939190](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200317205939190.png)

## 2.a打印菱形

```c++
#include<cstdio>                               //分成上下两部分打印       
#include<iostream>
using namespace std;
int main() {
	for (int i = 1; i <= 5; i++) {              //打印上半部分（5行）
		for (int j = 0; j <= 4 - i; j++) {      //上半部分空格打印 4行 4-3-2-1
			cout << " ";
		}
		for (int j = 1; j <= 2 * i - 1; j++) {  //  上半部分 * 打印 5行 1-3-5-7-9
			if (j % 2 == 0) {
				cout << " ";				    //偶数个挖空
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
	for (int i = 4; i > 0; i--) {
		for (int j = 1; j <= 5 - i; j++) {      //下半部分空格打印 4行 1-2-3-4
			cout << " ";
		}
		for (int j = 1; j <= 2 * i - 1; j++) {  //  下半部分 * 打印 4行 7-5-3-2-1
			if (j % 2 == 0) {					//偶数个挖空
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
	return 0;
}
```

![image-20200317210041752](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200317210041752.png)

## 2.b 打印空心菱形

```c++
#include<cstdio>                               //分成上下两部分打印       
#include<iostream>							   //可以看作是大菱形套了一个小的由" "组成的菱形 
using namespace std;
int main() {
	for (int i = 1; i <= 5; i++) {            //打印上半部分（5行）
		for (int j = 0; j <= 4 - i; j++) {    //  上半部分空格打印（4行 4-3-2-1）
			cout << " ";
		}
		cout << "*";                          //先打印一条边
		for (int j = 1; j <= 2 * i - 2; j++) {//再打印剩下部分 （4行 2-4-6-8）
			if (j == 2 * i - 2) {			  //仅在末尾输出"*"
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 4; i > 0; i--) {
		for (int j = 1; j <= 5 - i; j++) {        //下半部分空格打印 4行 1-2-3-4
			cout << " ";
		}
		cout << "*";
		for (int j = 1; j <= 2 * i - 2; j++) {	  //下半部分打印 3行 6-4-2
			if (j == 2 * i - 2) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
```

![image-20200317210132461](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200317210132461.png)

## 2.c 打印心型

```c++
#include<iostream>//分部分打印
#include<cstdio>
using namespace std;
int main() {
	for (int i = 1; i <= 3; i++) { //打印前三行
		for (int j = 0; j <= 3 - i; j++) {  //空格打印 2行 2-1
			cout << " ";
		}
		for (int j = 1; j <= 2 * i + 1; j++) { //"*"打印 3行 3-5-7 偶数挖空
			if (j % 2 == 0) {
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		for (int j = 1; j <= 9-2*i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= 2 * i + 1; j++) {
			if (j % 2 == 0) {
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
	for (int i = 1; i <= 10; i++) { //打印下半部分 10行
		for (int j = 0; j < i-1; j++) {//打印空格 10行 1-3-5-7-9-
			cout << " ";			  //   11-13-15-18-19				
		}
		for (int j = 1; j <= 21 - 2 * i; j++) {//打印下半部分"*" 19~1 公差为2 
			if (j % 2 == 0) {				   //偶数挖空
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
	return 0;
}
```

![image-20200317210244645](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200317210244645.png)

## 3 a 求两个有序数组的公共元素

```c++
#include<iostream>			//在二分查找和双指针法之间反复横跳 想来想去还是双指针吧
#include<vector>//在两个数组的起始位置设置两个指针
using namespace std;		//比较二者大小 谁大谁不懂，谁小谁往前走
int main(){
	int input_a, input_b ;
	vector<int> a;			//动态数组暂存
	vector<int> b;
	while (cin >> input_a){//连续读入
		if (input_a != -1) {
			a.push_back(input_a);
		}
		else {
			break;
		}
	}
	while (cin >> input_b){
		if (input_b != -1) {
			b.push_back(input_b);
		}
		else {
			break;
		}
	}
	int i = 0, j = 0;//设立两个指针
	while (i < a.size() && (j < b.size())){ //谁大谁不动 谁小谁往前走
		if (a[i] == b[j]) {             //相等则直接输出
		cout << a[i] << ' ';
		i++;
		j++;
		continue;
		}		
		else if (a[i] < b[j]) {      //b大则a的指针++
			i++;
		}		

		else {						//a大则b的指针++
			j++;
		}
	}
}
```



## 3.b求三个有序数组的公共元素

```c++
#include<iostream>			 //三指针 
#include<vector>			 //都相等则输出
using namespace std;		 //若不全相等 则找出最大值 
int Max(int a, int b, int c);//剩下两个指针向右移
int main() {
	int input_a, input_b,input_c;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	while (cin >> input_a) {
		a.push_back(input_a);
	}
	while (cin >> input_b) {
		b.push_back(input_b);
	}
	while (cin >> input_c) {
		c.push_back(input_c);
	}
	int i = 0, j = 0, k = 0;
	while (i < a.size() && j < b.size() && k < c.size) { //谁大谁不动 谁小谁往前走
		if (a[i] == b[j] && a[i] == c[k]) { //相等则直接输出
			cout << a[i] << ' ';
			i++;
			j++;
			k++;
			continue;
		}
		else if (i == a.size() && j == b.size() && k == c.size) { //如果某个数组取到端点
			break;												  //则直接跳出循环
		}
		else {							//剩下的所有情况 都先取最大值 然后两个较小的指针移动
			Max(a[i], b[j], c[k]);
			if (a[i] == Max(a[i], b[j], c[k])) {//a数组为最大时
				j++;							//数组b和c的指针移动
				k++;
			}
			else if (b[j] == Max(a[i], b[j], c[k])) {//b数组为最大时
				i++;								 //数组a和c的指针移动
				k++;
			}
			else if (c[k] == Max(a[i], b[j], c[k])) {//c数组为最大时
				i++;								 //数组a和b的指针移动
				j++;
			}
		}
	}
	return 0;
}
int Max(int a, int b, int c) {
	if (a > b && a > c) {
		return a;
	}
	else if (b > a && b > c) {
		return b;
	}
	else {
		return c;
	}
}
```

## 3.c求n个有序数组的公共元素

想不出解决n个的办法  归纳不出封装函数解决问题

## 4.求数组的最大值和次大值

```c++
#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> a;
	int input_a;
	while (cin >> input_a) {
		a.push_back(input_a);

	}
	int i = 0;
	int Max = 0;
	int Sub_Max = 0;
	while (i < a.size()){
		if (Max < a[i] && Sub_Max<a[i] ) { //如果都小  重置Max的值并把Max给Sub_Max
			Max = a[i];
			Sub_Max = Max;
		}
		if (Max > a[i] && Sub_Max < a[i]) { //如果比Max小但比Sub_Max大 则仅重置Sub_Max
			Sub_Max = a[i];
		}
		else {								//如果都大 则继续循环 i++
			continue;
		}	
		i++;
	}
	return 0;
}
```

## 5.给定一个n个整型元素的数组a，其中有一个元素出现次数超过n / 2，求这个元素

```c++
#include<iostream>	  	  //直接用排序做的
#include<vector>		  //对数组排序  
#include<algorithm>	      //中间的那个必然是出现频率最高的
using namespace std;		
int main() {
	int input_a;
	vector<int> a;			//动态数组暂存
	while (cin >> input_a) {//连续读入 数组的值
		if (input_a != -1) {
			a.push_back(input_a);
		}
		else {
			break;
		}
	}
	int temp;
	int i = (int)a.size / 2;
	for (int i = 0; i < a.size(); i++) {       //冒泡排序
		for (int j = 0; j < a.size() - 1; j++) { 
			if (a[j] > a[j + 1]) {	//前值大于后值 则后的值给前
				swap(a[j], a[j + 1]);
			}
		}
	}
	cout << a[i] << endl;
	return 0;
}
```

## 6.给定一个含有n个元素的整型数组，找出数组中的两个元素x和y使得abs(x - y)值最小

```c++
#include<iostream> //可能勉强算是贪心算法 大概。。。
#include<vector>
#include<cmath>
using namespace std;
int main() {
	vector<int>a;
	int input_a;
	while (cin >> input_a) {
		a.push_back(input_a);
	}
	int x = a[0];
	int y = a[1];
	int Min = abs(x - y);
	for (int i = 0; i < a.size(); i++) {  //遍历数组
		if (abs(a[i] - a[i + 1]) < Min) { //如果出现比Min更小的 则重置x y Min的值为当前值
			x = a[i];
			y = a[i - 1];
			Min = abs(a[i] - a[i + 1]);
		}
	}
	cout << "x = " << x << " "
		 << "y = " << y << " "
		 << "abs(x-y) = " 
		 << Min << endl;
	return 0;
}
```

## 7.给定含有1001个元素的数组，其中存放了1-1000之内的整数，只有一个整数是重复的，请找出这个数

```c++
#include <stdio.h>
#include <stdlib.h>		//仅有一个重复则值为
#include <time.h>
int main()
{
	int a[1001] = { 0 };
	for (int i = 0; i < 1000; ++i)
	{
		a[i] = i + 1;
	}
	srand(time(NULL));
	for (int i = 1000; i >= 2; --i)
	{
		int tmp1 = rand() % i + 1;
		int tmp2 = a[i - 1];
		a[i - 1] = a[tmp1 - 1];
		a[tmp1 - 1] = tmp2;
	}
	a[1000] = rand() % 1000 + 1;
	int Sum = 0;
	for (int i = 0; i < 1000; i++) {
		Sum += a[i];
	}
	for (int i = 1; i <= 1000; i++) {
		Sum -= i;
	}
	printf("%d\n", &Sum);
	return 0;
}
```

