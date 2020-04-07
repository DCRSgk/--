#include<iostream>
#include<cstdio>
#include"my_library.h"
using namespace std;
int main()
{
	int m, n;
	int path;
	scanf_s("%d %d", &m, &n);
	path = Factorial(m + n) / (Factorial(m) * Factorial(m + n - m));
	printf("走到（%d，%d），有%d种方法\n", m, n, path);
}
int Factorial(int n)
{
	long long m = 1;
	for(int i=1;i<=n;i++)
	{
		m *= i;
	}
	return m;
}