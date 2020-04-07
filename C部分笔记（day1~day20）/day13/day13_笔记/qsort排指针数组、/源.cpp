#include<iostream>
#include<time.h>
#include<cstdio>
int compare(const void* pleft, const void* pright)
{
	int* p1 = (int*)pleft;
	int* p2 = (int*)pright;
	return p1 - p2;
}
constexpr auto N = 10;
using namespace std;
int main() 
{
	int arr[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}
	qsort(arr, N, sizeof(int), compare);

}