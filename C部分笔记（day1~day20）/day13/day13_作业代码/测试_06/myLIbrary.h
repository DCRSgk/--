#define _CAT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
using namespace std;
typedef struct list
{
	char val;
	struct list* pNext;
}List_t,*pList_t;
void headInSert(pList_t* pphead, pList_t* pptail, char val);
void tailInSert(pList_t* pphead, pList_t* pptail, char val);
void print(pList_t phead);
void add(pList_t phead1, pList_t phead2, pList_t* ppHeadRes, pList_t* ppTailRes);
void addPos(pList_t phead1, pList_t phead2, pList_t* ppHeadRes, pList_t* ppTailRes);
void minusPos(pList_t phead1, pList_t phead2, pList_t* ppHeadRes, pList_t* ppTailRes);
int compare(pList_t phead1, pList_t phead2);
void reverse(pList_t* pphead);