#include<iostream>  //写了个函数求当前日期到公元0年1月1号是多少天
#include<cstdio>	//将天数和7取余 得到是几就可以反推出当天是星期几
#include<cmath>		// 公元1月1号，因为教皇格里戈八世抹去的10天 按照计算机的推理是周一
int date_sum(int year, int month, int day);
int main() {
	char c [7] = { 'SUN','MON','TUE','WED','THU','FRI','SAT' };
	int year, month, day;
	int date_total;
	int i;
	scanf_s("%d %d %d", &year, &month, &day);
	date_total = date_sum(year, month, day)-1;
	switch (date_total % 7){
	case 0:printf("%d年%d月%d日是星期一", year, month, day); break;
	case 1:printf("%d年%d月%d日是星期二", year, month, day); break;
	case 2:printf("%d年%d月%d日是星期三", year, month, day); break;
	case 3:printf("%d年%d月%d日是星期四", year, month, day); break;
	case 4:printf("%d年%d月%d日是星期五", year, month, day); break;
	case 5:printf("%d年%d月%d日是星期六", year, month, day); break;
	case 6:printf("%d年%d月%d日是星期天", year, month, day); break;
	}
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