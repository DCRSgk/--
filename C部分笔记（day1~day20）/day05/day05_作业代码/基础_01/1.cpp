#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool isprime(int m);
int main() {
	int m;
	while (scanf_s("%d", &m) != EOF) {
		if (isprime(m) == false) {
			printf("%d不是质数\n", m);
		}
		else {
			printf("%d是质数\n", m);
		}
	}
	return 0;
}
bool isprime(int m) {
	if (m == 2 || m == 3) {
		return true;
	}
	for (int i = 0; i <= sqrt(m); i++){
		if (m % i == 0) {
			return false;
			
		}
	}
	return true;
}
//bool isprime(int m) {
//	int j = 2;
//	do {
//		if (m == 2 || m == 3) {
//			return true;
//			break;
//		}
//		else if (m % j == 0) {
//			return false;
//			break;
//		}
//		j++;
//	} while (j > m);
//	return true;
//}
//bool isprime (int m){
//	int j = 2;
//	while ( j > m-1) {
//		if (m == 2 || m == 3) {
//			return true;
//		}
//		if (m % j == 0) {
//			return false;
//			break;
//		}
//		j++;
//	}
//	return true;
//}

