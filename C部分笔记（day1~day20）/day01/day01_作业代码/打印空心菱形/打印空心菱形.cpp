#include<cstdio>                               //�ֳ����������ִ�ӡ       
#include<iostream>							   //���Կ����Ǵ���������һ��С����" "��ɵ����� 
using namespace std;
int main() {
	for (int i = 1; i <= 5; i++) {            //��ӡ�ϰ벿�֣�5�У�
		for (int j = 0; j <= 4 - i; j++) {    //  �ϰ벿�ֿո��ӡ��4�� 4-3-2-1��
			cout << " ";
		}
		cout << "*";                          //�ȴ�ӡһ����
		for (int j = 1; j <= 2 * i - 2; j++) {//�ٴ�ӡʣ�²��� ��4�� 2-4-6-8��
			if (j == 2 * i - 2) {			  //����ĩβ���"*"
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 4; i > 0; i--) {
		for (int j = 1; j <= 5 - i; j++) {        //�°벿�ֿո��ӡ 4�� 1-2-3-4
			cout << " ";
		}
		cout << "*";
		for (int j = 1; j <= 2 * i - 2; j++) {	  //�°벿�ִ�ӡ 3�� 6-4-2
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
