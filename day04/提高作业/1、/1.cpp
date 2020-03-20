#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int every_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int year, month, day;
	int date_sum =0;
	scanf_s("%d %d %d", &year, &month, &day);
	if (month > 1) {
		for (int i = 0; i < month - 1; i++) {
			date_sum += every_month[i];
		}
		date_sum += (year % 4 == 0 && year % 100 == 0 || year % 400 == 0);
		date_sum += day;
	}
	else {
		date_sum += day;
	}
	cout << "今天是" << year << "的第" << date_sum << "天" << endl;
	
	
	return 0;
}