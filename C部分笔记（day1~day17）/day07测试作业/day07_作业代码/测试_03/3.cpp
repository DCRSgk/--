#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
void strike_out(char* c,char n);
int main()
{
	const int N = 1024;
	char str[N];
	char n;
	while (gets_s(str)!=NULL)
	{
		scanf("%c", &n);
		strike_out(str,n);
	}
	return 0;
}
void strike_out(char* c, char n)
{
	char* temp = (char*)malloc((strlen(c)));
	strcpy(temp, c);
	int i = 0;
	while (*temp != '\0')
	{
		if (*temp == 'n')
		{
			c[i++] = *temp; //如果找到则直接跳到下一个
		}
		temp++;
	}
	c[i] = '\0';
	printf("%s\n", c);
}