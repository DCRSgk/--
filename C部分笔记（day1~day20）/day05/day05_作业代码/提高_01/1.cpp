#include<iostream>   //���������
#include<cstdio>	 //��һ����������������ǵ��ڵڶ��������������
#include<cmath>		 //��˵Ľ�����е�һ������������͵ڶ������������
using namespace std;
int main() {
	int c1, r1;          //��һ�������������
	int c2, r2;          //�ڶ��������������
	const int N = 1024;
	int A[N][N];
	int	B[N][N];
	int C[N][N]; //��ž�����
	cin >> r1 >> c1;
	cin >> r2 >> c2;
	for (int i = 0; i < r1; i++) {	//�����һ������
		for (int j = 0; j < c1; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < r1; i++) {//����ڶ�������
		for (int j = 0; j < c1; j++) {
			cin >> B[i][j];
		}
	}
	for (int i = 0; i < r1; i++) {     //�¾�����е��ھɾ������ 
		for (int j = 0; j < c1; j++) { //�¾�����е��ھɾ������
			for (int m = 0; m < r1; m++) { //���ƾ���˷�
				C[i][j] = C[i][j] + A[i][m] * B[m][j];
			}
		}
	}
	if (c1 != r2) {
		cout << "Error" << endl;
	}
	else {
		for (int i = 0; i < r1; i++) {     //�������˷���ֵ
			for (int j = 0; j < c1; j++) {
				cout << C[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}