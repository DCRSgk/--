#include<iostream>
#include<cstdio>
#include<string>
constexpr auto N = 1024;
using namespace std;
int compare(const void* lefe, const void* right);
int main()
{
	char Arr[N];
	while (gets_s(Arr)!=NULL)
	{
		cout << endl;
		int len = strlen(Arr);
		qsort(Arr, len, sizeof(char), compare);
		for (int i = 0; i < len; i++)
		{
			cout << Arr[i];
			
		}
		cout << endl;
		cout << "--------------------------" << endl;	
	}
}
int compare(const void* left, const void* right)
{
	char* p1 = (char*)left;
	char* p2 = (char*)right;
	return *p1 - *p2;
}