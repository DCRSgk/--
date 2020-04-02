#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	int num;
	float score;
	char name[20];
}student_t;
int main(int argc, char* argv[])
{
	student_t s = { 1001,98.55,"lele" };
	char bur[1024];
	sprintf(bur, "%d %5.2f %s", s.num, s.score, s.name);
	//将s存进bur
	memset(&s, 0, sizeof(student_t));
	sscanf(bur, "%d %5.2f %s", &s.num, &s.score, s.name);
	//将bur存入s
	s.num = atoi("123");//字符串转整数
	system("pause");
}