#include <stdio.h>
#include <stdlib.h>

union data{
	int i;
	char c;
	float f;
};
typedef struct student{
	int num;
	float score;
}Student_t;

enum weekday{sun,mon,tue,wed=20,thu,fri,sat};

int main()
{
	union data a;//�����壬���������г�Ա����һ��ռ�
	Student_t s;
	enum weekday workday;
	a.i=10;
	a.c='A';
	a.f=98.5;
	s.num=10;
	s.score=96;
	printf("wed=%d\n",wed);
	workday=mon;
	printf("workday=%d\n",workday);
	system("pause");
}