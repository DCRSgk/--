#include<iostream>
#include<cstdio>
#include<string>
#include<time.h>
constexpr auto N = 1024;
using namespace std;
int partition(int *data, int len, int k);
int main()
{
	int arr[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}

}
int partition(int* data, int len, int k) //������X�����ŵ���ߣ�С��X�����ŵ��ұ�
{ 

}