#include<iostream>  
#include<cstdio>	
#include<cmath>		
int date_sum(int year, int month, int day,int N);
int main() {
	char c[7] = { 'SUN','MON','TUE','WED','THU','FRI','SAT' }; //日期
	int year, month, day,N;
	int date_total;
	int i;
	scanf_s("%d %d %d %d", &year, &month, &day,&N);
	/*switch (date_sum(year,month,day,N)) {
	case 0:printf("%d年%d月%d日是星期一", year, month, day); break;
	case 1:printf("%d年%d月%d日是星期二", year, month, day); break;
	case 2:printf("%d年%d月%d日是星期三", year, month, day); break;
	case 3:printf("%d年%d月%d日是星期四", year, month, day); break;
	case 4:printf("%d年%d月%d日是星期五", year, month, day); break;
	case 5:printf("%d年%d月%d日是星期六", year, month, day); break;
	case 6:printf("%d年%d月%d日是星期天", year, month, day); break;
	}*/
	if()
	return 0;
}
int date_sum(int year, int month, int day,int N) {      //当前日期N天之后是星期几
	int date_total;
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
	date_total = date_sum - 1 + N;
	return date_total % 7;

}