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