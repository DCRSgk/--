#include<iostream>   //�����������署�İ�λ�����������˼·
#include<cstdio>     //��������� �ų������ظ�������
using namespace std; //ʣ������ȫ��һ��result�� ��Ҫ�ٴα����������ֿ�
int main() {	     //����ǰ��Ҫ�Խ��а�λ������ ��ȡ����һ������
	int a[] = { 1,1,2,2,3,3,4,4,5,5,6,7};
	int result = 0;
	int left = 0;
	int right = 0;
	for (int i = 0; i < 12; i++) {
		result = result^ a[i];
	}
	result = result & (-result); 
	for (int i = 0; i < 12; i++) { //�ٴα���
		if (a[i] & result) { //���һ��
			left = left ^ a[i];
		}
		else {
			right = right ^ a[i];
		}
	}
	cout << left << endl;
	cout << right << endl;
	return 0;
}