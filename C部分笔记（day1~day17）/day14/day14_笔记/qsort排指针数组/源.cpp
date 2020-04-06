#include<cstdio>
#include<iostream>
#define N 10
typedef struct list
{
	int num;
	list* pNext;
}list_t,*pList;
int comparePointer(const void* pleft, const void* pright)
{
	pList* p1 = (pList*)pleft;
	pList* p2 = (pList*)pright;
	return (*p1)->num - (*p2)->num;
}
int main()
{
	int arr[N];
	int i;
	int listlen = 0;
	pList phead, ptail, pNew,pCur;
	pList* pArr;

	phead = ptail = NULL;
	while (scanf_s("%d",&i)!=EOF)
	{
		pNew = (pList)calloc(1, sizeof(pList));
		pNew->num = i;
		if (phead == NULL)
		{
			phead = pNew;
			ptail = pNew;
		}
		else
		{
			pNew->pNext = phead;
			phead = pNew;
		}
		listlen++;
	}
	pArr =(pList*) malloc(listlen * sizeof(pList));
	pCur = phead;
	for (int i = 0; i < listlen; i++)
	{
		pArr[i] = pCur;
		pCur = pCur->pNext;
	}
	qsort(pArr, listlen, sizeof(pList),comparePointer );
	for (int i = 0; i < N; i++)
	{
		printf("%3d", pArr[i]->num);

	}
	printf("\n");
	//Ïú»ÙÁ´±í
	
	while (phead!=NULL) 
	{
		pCur = phead;
		phead = phead->pNext;
		free(pCur);
		pCur == NULL;	
	}
	phead == NULL;
	free(pArr);
}
