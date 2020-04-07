#include"myLIbrary.h"
int main()
{
	char c;
	pList_t pHead1 = NULL;  //first list
	pList_t pTail1 = NULL;
	pList_t pHead2 = NULL;  //secend list
	pList_t pTail2 = NULL;
	pList_t pHailRes = NULL;	//result list
	pList_t pTailRes = NULL;
	while (scanf_s("%c",&c)!=EOF)
	{
		if (c == '\n') //好用 记下来
		{ 
			break;
		}
		tailInSert(&pHead1, &pTail1, c);
	}
	while (scanf_s("%c", &c) != EOF)
	{
		if (c == '\n') 
		{
			break;
		}
		tailInSert(&pHead2, &pTail2, c);
	}
	//print(pHead1);
	//print(pHead2);
	add(pHead1, pHead2, &pHailRes, &pTailRes);
	print(pHailRes);
}
