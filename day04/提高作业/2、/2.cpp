#include<iostream>  //д�˸�������ǰ���ڵ���Ԫ0��1��1���Ƕ�����
#include<cstdio>	//�������������ݵ����������������
#include<cmath>		//��������4���������ж��ڼ��Ƿ������� 
using namespace std;//4��400��Ϊ���� ��1��
int date_sum(int year, int month, int day);
int main() {
	int year1, month1, day1;
	int year2, month2, day2;
	int date_total =0;
	int smaller_year;
	scanf_s("%d %d %d", &year1, &month1, &day1);
	scanf_s("%d %d %d", &year2, &month2, &day2);
	if (abs(year1 - year2) > 4) { //�����ж� 
		smaller_year = year1 < year2 ? year1 : year2;
		for (int i = smaller_year; i >= abs(year1 - year2); i++) {
			date_total += (i % 4 == 0 && i % 100 || i % 400);
		}
		date_total = abs(date_sum(year1, month1, day1) - date_sum(year2, month2, day2));
	}
	else if ((abs(year1 - year2) < 4) &&  //�������ڳ��ֿ��������� ��ֱ��+1
		((year1 % 4 == 0 && year1 % 100 || year1 % 400) || 
		(year2 % 4 == 0 && year2 % 100 || year2 % 400)) ){
		date_total = abs(date_sum(year1, month1, day1) - date_sum(year2, month2, day2)) + 1;
	}
	else {
		date_total = abs(date_sum(year1, month1, day1) - date_sum(year2, month2, day2));
	}
	cout << "���������" << date_total << "��";
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