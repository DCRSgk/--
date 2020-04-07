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
	//printf("%d%f%s\n", s.num, s.score, s.name);
	FILE* fp;
	char buf[1024];
	int ret;
	if (argc != 2)
	{
		printf("error args\n");
	}
	fp = fopen(argv[1], "r+");
	if (NULL == fp)
	{
		perror("fopen");
		goto error;
	}
	//memset(&s, 0, sizeof(student_t));
	//scanf("%d%f%s", &s.num, &s.score, s.name);
	//fscanf(fp,"%d%f%s", &s.num, &s.score, s.name);
	//fprintf(fp, "%d%f%s\n", s.num, s.score, s.name);
	while (memset(&s, 0, sizeof(student_t)), fscanf(fp, "%d%f%s", &s.num, &s.score, s.name))
	{
		printf("%d%f%s\n", s.num, s.score, s.name);
	}
	fclose(fp);
error:
	system("pause");
}