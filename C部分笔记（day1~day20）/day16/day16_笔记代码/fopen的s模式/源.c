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
	FILE* fp;
	fp = fopen("file.txt", "w+");
	//��file�����û����ֱ�Ӵ���

}