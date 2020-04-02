#include<iostream>
#include<cstdio>
#include<string>
#include<time.h>
constexpr auto N = 10;
using namespace std;
typedef struct list
{
	int num;
	list* pNext;
}table_t,*ptable_t;
void inList(ptable_t* pphead, ptable_t* pptail, int val);