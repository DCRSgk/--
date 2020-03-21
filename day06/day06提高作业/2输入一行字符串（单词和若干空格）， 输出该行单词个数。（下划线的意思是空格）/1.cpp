#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main() {
	const int N = 1024;
	char c;
	int i = 0;
	int word = 0;
	int count = 0;
	char a[N] ;
	gets_s(a);
	while (c = a[i++]) {
		if (c == ' ') {
			word = 0;
		}
		else if (word == 0) {
			count++;
			word = 1;
		}
	}
	cout << count << endl;
	return 0;
}
