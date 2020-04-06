#include<iostream>
#include<cstdio> //遍历并异或 得到重复的数字
constexpr auto N = 10;
using namespace std;
int main() {
	int m;
	int a[N] = { 1,1,2,2,3,3,4,5,6 };
	int result = 0;
	for (int i = 0; i < 7; i++) {
		m = a[i];
		for (int j = 0; j < 7; j++) {
			if (m == a[j]) {
				continue;
			}
		}

	}
	cout << result;
	return 0;
}
