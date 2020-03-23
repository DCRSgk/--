#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
void replace(char* c);
int main() 
{
	const int N = 1024;
	char str[N];
	while (gets_s(str) != NULL)
	{
		replace(str);
	}
	return 0;
}
void replace(char* c)
{
	char* temp = (char*)malloc((strlen(c)));
	strcpy(temp, c);
	int i = 0;
	while(*temp != '\0')
	{
		if (*temp == ' ')
		{
			c[i++] = '%';
			c[i++] = '0';
			c[i++] = '2';
			c[i++] = '0';
		}
		else
		{
			c[i++] = *temp;
		}
		temp++;
	}
	c[i] = '\0';
	printf("%s\n", c);
}