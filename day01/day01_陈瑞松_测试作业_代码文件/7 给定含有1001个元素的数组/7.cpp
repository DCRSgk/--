#include <stdio.h>
#include <stdlib.h>		//仅有一个重复则值为
#include <time.h>
int main()
{
	int a[1001] = { 0 };
	for (int i = 0; i < 1000; ++i)
	{
		a[i] = i + 1;
	}
	srand(time(NULL));
	for (int i = 1000; i >= 2; --i)
	{
		int tmp1 = rand() % i + 1;
		int tmp2 = a[i - 1];
		a[i - 1] = a[tmp1 - 1];
		a[tmp1 - 1] = tmp2;
	}
	a[1000] = rand() % 1000 + 1;
	int Sum = 0;
	for (int i = 0; i < 1000; i++) {
		Sum += a[i];
	}
	for (int i = 1; i <= 1000; i++) {
		Sum -= i;
	}
	printf("%d\n", &Sum);
	return 0;
}