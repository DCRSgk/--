#include<stdio.h>
int main() {
	for (int i = 1; i <= 3; i++) { //��ӡǰ����
		for (int j = 0; j <= 3 - i; j++) {  //�ո��ӡ 2�� 2-1
			printf(" ");
		}
		for (int j = 1; j <= 2 * i + 1; j++) { //"*"��ӡ 3�� 3-5-7 ż���ڿ�
			if (j % 2 == 0) {
				printf(" ");
			}
			else {
				pritnf("*");
			}
		}
		for (int j = 1; j <= 9-2*i; j++) {
			printf(" ");
		}
		for (int j = 1; j <= 2 * i + 1; j++) {
			if (j % 2 == 0) {
				printf(" "); 
			}
			else {
				pritnf("*");
			}
		}
		printf("\n");
	}
	for (int i = 1; i <= 10; i++) { //��ӡ�°벿�� 10��
		for (int j = 0; j < i-1; j++) {//��ӡ�ո� 10�� 1-3-5-7-9-
			printf(" ");			   //             11-13-15-18-19				
		}
		for (int j = 1; j <= 21 - 2 * i; j++) {//��ӡ�°벿��"*" 19~1 ����Ϊ2 
			if (j % 2 == 0) {				   //ż���ڿ�
				printf(" ");
			}
			else {
				pritnf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
