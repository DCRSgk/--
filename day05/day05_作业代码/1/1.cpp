#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
void func(int arr[]) {
	int m;
	m = sizeof(arr);
	cout << "函数内的sizeof为" << m << endl;
}
int main() {
	int arr[10] = { 0 };
	func(arr);
	cout << "主函数的sizeof为" << sizeof(arr) << endl;
}