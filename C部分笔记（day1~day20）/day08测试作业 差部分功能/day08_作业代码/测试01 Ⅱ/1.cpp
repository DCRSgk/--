#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
constexpr auto N = 1024;
void bigadd(char num1[],int num1_size, char num2[],int num2_size);
int main()
{
	int num1_size, num2_size;
	char num1[N];
	char num2[N];
	cin >> num1;
	cin >> num2;
	num1_size = strlen(num1);
	num2_size = strlen(num1);
	bigadd(num1, num1_size, num2, num2_size);
}
void bigadd(char num1[], int num1_size, char num2[], int num2_size)
{
	int num1_in[N];
	int num2_in[N];
	int num = '0', i, k, j, tmp;
	for (int i = num1_size - 1, j = 0; i >= 0; i--) // char的最后一位是\n
	{
		num1_in[j++] = num1[i] - '0';
	}
	for (int i = num2_size - 1, j = 0; i >= 0; i--)
	{
		num2_in[j++] = num1[i] - '0';
	}
	int Sum_size = num1_size > num2_size ? num1_size : num2_size;
	for (int i = 0; i <= Sum_size; i++)
	{
		num1_in[i] += num2_in[i];
		if (num1_in[i] >= 10)  //如果超过十则进位
		{
			num1_in[i + 1] += 1;
			num1_in[i] -= 10;
		}
	}
	int i;
	for (i = Sum_size - 1; i >= 0; i--)
	{
		if (i > 0)
			for (; i >= 0; i--)
			{
				cout << num1_in[i];
			}
		else
		{
			cout << 0;
		}
		cout << endl;
	}
}