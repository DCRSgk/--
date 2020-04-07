#define _CRT_SECURE_NO_WARNINGS
constexpr auto N = 10;
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int Arr[N] = { 1,2,2,4,5,6,7,7,8,9 };	
	cout << "删除前数组为" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << Arr[i];
	}
	cout << endl;
	cout << "----------" << endl;
	cout << "删除后数组为" << endl;
	for (int i = 0; i < 10; i++)
	{
		int j = i + 1;
		if (Arr[i] == Arr[j])
		{
			i = j;
			j++;
		}
		cout << Arr[i];
	}
	cout << endl;
	cout << "----------" << endl;
}

