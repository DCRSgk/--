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
