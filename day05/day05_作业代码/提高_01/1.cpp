#include<iostream>   //两矩阵相乘
#include<cstdio>	 //第一个矩阵的列数必须是等于第二个矩阵的行数。
#include<cmath>		 //相乘的结果具有第一个矩阵的行数和第二个矩阵的列数
using namespace std;
int main() {
	int c1, r1;          //第一个矩阵的行列数
	int c2, r2;          //第二个矩阵的行列数
	const int N = 1024;
	int A[N][N];
	int	B[N][N];
	int C[N][N]; //存放矩阵用
	cin >> r1 >> c1;
	cin >> r2 >> c2;
	for (int i = 0; i < r1; i++) {	//输入第一个矩阵
		for (int j = 0; j < c1; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < r1; i++) {//输入第二个矩阵
		for (int j = 0; j < c1; j++) {
			cin >> B[i][j];
		}
	}
	for (int i = 0; i < r1; i++) {     //新矩阵的行等于旧矩阵的列 
		for (int j = 0; j < c1; j++) { //新矩阵的列等于旧矩阵的行
			for (int m = 0; m < r1; m++) { //控制矩阵乘法
				C[i][j] = C[i][j] + A[i][m] * B[m][j];
			}
		}
	}
	if (c1 != r2) {
		cout << "Error" << endl;
	}
	else {
		for (int i = 0; i < r1; i++) {     //输出矩阵乘法的值
			for (int j = 0; j < c1; j++) {
				cout << C[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}