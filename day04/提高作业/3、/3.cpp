#include<iostream>  //д�˸�������ǰ���ڵ���Ԫ0��1��1���Ƕ�����
#include<cstdio>	//��������7ȡ�� �õ��Ǽ��Ϳ��Է��Ƴ����������ڼ�
#include<cmath>		// ��Ԫ1��1�ţ���Ϊ�̻ʸ�������Ĩȥ��10�� ���ռ��������������һ
int date_sum(int year, int month, int day);
int main() {
	char c [7] = { 'SUN','MON','TUE','WED','THU','FRI','SAT' };
	int year, month, day;
	int date_total;
	int i;
	scanf_s("%d %d %d", &year, &month, &day);
	date_total = date_sum(year, month, day)-1;
	switch (date_total % 7){
	case 0:printf("%d��%d��%d��������һ", year, month, day); break;
	case 1:printf("%d��%d��%d�������ڶ�", year, month, day); break;
	case 2:printf("%d��%d��%d����������", year, month, day); break;
	case 3:printf("%d��%d��%d����������", year, month, day); break;
	case 4:printf("%d��%d��%d����������", year, month, day); break;
	case 5:printf("%d��%d��%d����������", year, month, day); break;
	case 6:printf("%d��%d��%d����������", year, month, day); break;
	}
	return 0;
}
int date_sum(int year, int month, int day) {      //�͹�ԪԪ��1��1����������
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