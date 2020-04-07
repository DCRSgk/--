#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include <stack>
using namespace std;
typedef struct myList
{
	int num;
	char name[20];
	float cham;
	struct myList* pNext;
}List_t,*pList_t;
void ListDelete(pList_t* ppHead, List_t** ppTail, int deleteNum);
void print(pList_t p);
pList_t currentList(pList_t p);
void getLast4th(pList_t head);
bool getRing(pList_t head);