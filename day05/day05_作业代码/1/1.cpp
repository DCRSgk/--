#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
void func(int arr[]) {
	int m;
	m = sizeof(arr);
	cout << "�����ڵ�sizeofΪ" << m << endl;
}
int main() {
	int arr[10] = { 0 };
	func(arr);
	cout << "��������sizeofΪ" << sizeof(arr) << endl;
}