#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main() {
	const int N = 1024;
	char c;
	int i = 0;
	int word = 0;
	char a[N] ;
	gets_s(a);
	while (c = a[i++]) {
		if (c != ' ') {	  //û�����ո�ͳ������
			cout<< c;
			word = 1;
		}
		else if (c == ' '&&word ==1) { //�����¸��ո��ʱ����
			word = 0;
			cout << endl;
		}
		else {  //���һ��ʼ���ǿո���continue
			
			continue;
		}
	}
	return 0;
}
