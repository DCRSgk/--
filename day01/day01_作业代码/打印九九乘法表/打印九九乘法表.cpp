//���ڲ������ĸ��汾�������Ҷ�д�� 
#include<stdio.h>
int main() {
	//�����汾
	for (int i = 1; i <= 9; i++) {        //������
		for (int j = 1; j <= 9; j++) {      //������
			if (j == 1) {
				printf("%d*%d=%2d", j, i, i * j);
			}
			else {
				printf("%2d*%d=%2d", i, j, i * j);
			}	
		}
		printf("\n");
	}
	//�����ǰ汾
	//for (int i = 1; i <= 9; i++) {    //������
	//	for (int j = 9; j >= i; j--) {//������
	//		if (j == 9) {
	//			printf("%d*%d=%d", (10 - j),  i , i * (10 - j));
	//		}
	//		else {
	//			printf("%2d*%d=%d", (10 - j), i, i * (10 - j));
	//		}
	//	}
	//	printf("\n");
	//}
	//�����ǰ汾
	//for (int i = 1; i <= 9; i++) {    //������
	//	for (int j = 1; j <= i; j++) { //������
	//		if (j == 1) {
	//			printf("%d*%d=%2d", j, i, i * j);
	//		}
	//		else {
	//			printf("%2d*%d=%2d", j, i, i * j);
	//		}
	//	}
	//	printf("\n");
	//}
	return 0;
}

