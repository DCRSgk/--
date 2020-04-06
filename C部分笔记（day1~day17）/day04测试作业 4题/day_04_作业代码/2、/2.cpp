#include<iostream>  //写了个函数求当前日期到公元0年1月1号是多少天
#include<cstdio>	//二者想减加上年份的闰年就是相差多少天
#include<cmath>		//如果年相差4年以上则判断期间是否有闰年 
using namespace std;//4和400均为闰年 加1天
int date_sum(int year, int month, int day);
int main() {
	int year1, month1, day1;
	int year2, month2, day2;
	int date_total =0;
	int smaller_year;
	scanf_s("%d %d %d", &year1, &month1, &day1);
	scanf_s("%d %d %d", &year2, &month2, &day2);
	if (abs(year1 - year2) > 4) { //年数判断 
		smaller_year = year1 < year2 ? year1 : year2;
		for (int i = smaller_year; i >= abs(year1 - year2); i++) {
			date_total += (i % 4 == 0 && i % 100 || i % 400);
		}
		date_total = abs(date_sum(year1, month1, day1) - date_sum(year2, month2, day2));
	}
	else if ((abs(year1 - year2) < 4) &&  //四年以内出现跨闰年的情况 则直接+1
		((year1 % 4 == 0 && year1 % 100 || year1 % 400) || 
		(year2 % 4 == 0 && year2 % 100 || year2 % 400)) ){
		date_total = abs(date_sum(year1, month1, day1) - date_sum(year2, month2, day2)) + 1;
	}
	else {
		date_total = abs(date_sum(year1, month1, day1) - date_sum(year2, month2, day2));
	}
	cout << "两日期相差" << date_total << "天";
	return 0;
}
int date_sum(int year, int month, int day) {      //和公元元年1月1日相差多少天
	int every_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int date_sum = 0; 
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
	date_sum += 365 * year - 1;
	return date_sum;

}