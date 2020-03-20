#include<iostream>
#include<cstdio> //遍历并异或 得到重复的数字
using namespace std;
int main() {
	int a[7] = { 1,1,2,2,3,3,4 };
	int result = 0;
	for (int i = 0; i < 7 ; i++) {
		result = result ^ a[i];
	}
	cout << result;
	return 0;
}