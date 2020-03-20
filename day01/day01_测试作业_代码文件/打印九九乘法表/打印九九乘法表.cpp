//由于不懂是哪个版本的所以我都写了 
#include<stdio.h>
int main() {
	//正常版本
	for (int i = 1; i <= 9; i++) {        //控制行
		for (int j = 1; j <= 9; j++) {      //控制列
			if (j == 1) {
				printf("%d*%d=%2d", j, i, i * j);
			}
			else {
				printf("%2d*%d=%2d", i, j, i * j);
			}	
		}
		printf("\n");
	}
	//倒三角版本
	//for (int i = 1; i <= 9; i++) {    //控制行
	//	for (int j = 9; j >= i; j--) {//控制列
	//		if (j == 9) {
	//			printf("%d*%d=%d", (10 - j),  i , i * (10 - j));
	//		}
	//		else {
	//			printf("%2d*%d=%d", (10 - j), i, i * (10 - j));
	//		}
	//	}
	//	printf("\n");
	//}
	//正三角版本
	//for (int i = 1; i <= 9; i++) {    //控制行
	//	for (int j = 1; j <= i; j++) { //控制列
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

