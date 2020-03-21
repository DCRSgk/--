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
		if (c != ' ') {	  //没读到空格就持续输出
			cout<< c;
			word = 1;
		}
		else if (c == ' '&&word ==1) { //读到下个空格的时候换行
			word = 0;
			cout << endl;
		}
		else {  //如果一开始就是空格则continue
			
			continue;
		}
	}
	return 0;
}
