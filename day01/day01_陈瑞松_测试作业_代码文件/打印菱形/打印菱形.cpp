#include<cstdio>                               //�ֳ����������ִ�ӡ       
#include<iostream>
using namespace std;
int main() {
	for (int i = 1; i <= 5; i++) {              //��ӡ�ϰ벿�֣�5�У�
		for (int j = 0; j <= 4 - i; j++) {      //  �ϰ벿�ֿո��ӡ 4�� 4-3-2-1
			cout << " ";
		}
		for (int j = 1; j <= 2 * i - 1; j++) {  //  �ϰ벿�� * ��ӡ 5�� 1-3-5-7-9
			if (j % 2 == 0) {
				cout << " ";				    //ż�����ڿ�
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
	for (int i = 4; i > 0; i--) {
		for (int j = 1; j <= 5 - i; j++) {      //�°벿�ֿո��ӡ 4�� 1-2-3-4
			cout << " ";
		}
		for (int j = 1; j <= 2 * i - 1; j++) {  //  �°벿�� * ��ӡ 4�� 7-5-3-2-1
			if (j % 2 == 0) {					//ż�����ڿ�
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