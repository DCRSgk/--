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
			cout << " ";			   //             11-13-15-18-19				
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