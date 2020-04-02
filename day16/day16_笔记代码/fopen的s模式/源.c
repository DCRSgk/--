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
	//打开file，如果没有则直接创建

}