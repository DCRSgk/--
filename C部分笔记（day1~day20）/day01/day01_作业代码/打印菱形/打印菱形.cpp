#include<cstdio>                               //分成上下两部分打印       
#include<iostream>
using namespace std;
int main() {
	for (int i = 1; i <= 5; i++) {              //打印上半部分（5行）
		for (int j = 0; j <= 4 - i; j++) {      //  上半部分空格打印 4行 4-3-2-1
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