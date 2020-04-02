#include"myLIbrary.h"

void headInSert(pList_t* pphead, pList_t* pptail, char val) 
{
	pList_t pNew = (pList_t)calloc(1, sizeof(List_t));
	pNew->val = val;
	if (*pphead == NULL)
	{	
		*pphead = pNew;
		*pptail = pNew;
	}
	else
	{
		pNew->pNext = *pphead;
		*pphead = pNew;
	}
}

void tailInSert(pList_t* pphead, pList_t* pptail, char val)
{
	pList_t pNew = (pList_t)calloc(1, sizeof(List_t));
	pNew->val = val;
	if (*pphead == NULL)
	{
		*pphead = pNew;
		*pptail = pNew;
	}
	else
	{
		(*pptail)->pNext = pNew; //->优先级比*高
		*pptail = pNew;
	}
}

void print(pList_t phead)
{
	while (phead)
	{
		printf("%c", phead->val);
		phead = phead->pNext;
	}
	printf("\n");
}

void add(pList_t phead1, pList_t phead2, pList_t* ppHeadRes, pList_t* ppTailRes)
{
	if (phead1->val == '-' && phead2->val == '-') //两负
	{
		addPos(phead1->pNext, phead2->pNext, ppHeadRes, ppTailRes);
		headInSert(ppHeadRes, ppTailRes, '-');
	}
	else if (phead1->val == '-') //如果第一个数为负，比较时需要移动符号位
	{							//phead1->pNext
		if (compare(phead1, phead2) > 0) //如果一的绝对值大于二
		{
			minusPos(phead1->pNext, phead2, ppHeadRes, ppTailRes);
			headInSert(ppHeadRes, ppTailRes, '-');
		}
		else if (compare(phead1->pNext, phead2) == 0)
		{
			headInSert(ppHeadRes, ppHeadRes, '0');
		}
		else
		{
			minusPos(phead2, phead1->pNext, ppHeadRes, ppTailRes);
		}
	}
	else if (phead2->val=='-')
	{
		if (compare(phead1, phead2) > 0)//如果二的绝对值大于一
		{
			minusPos(phead1, phead2->pNext, ppHeadRes, ppTailRes);

		}
		else if (compare(phead1, phead2->pNext) == 0)
		{
			headInSert(ppHeadRes, ppHeadRes, '0');
		}
		else
		{
			minusPos(phead2->pNext, phead1, ppHeadRes, ppTailRes);
			headInSert(ppHeadRes, ppTailRes, '-');
		}

	}
	else
	{
		addPos(phead1, phead2, ppHeadRes, ppTailRes);
	}
}

void addPos(pList_t phead1, pList_t phead2, pList_t* ppHeadRes, pList_t* ppTailRes)
{
	reverse(&phead1);
	reverse(&phead2);
	int remain = 0;
	while (phead1&&phead2)
	{
		char val = phead1->val + phead2->val + remain -'0';
		if (val > '9')
		{
			val -= 10;
			remain = 1;
		}
		else
		{
			remain = 0;
		}
		tailInSert(ppHeadRes, ppTailRes, val);
		phead1 = phead1->pNext;
		phead2 = phead2->pNext;
	}
	while (phead1)
	{
		char val = phead1->val + remain ;
		tailInSert(ppHeadRes, ppTailRes, val);
		phead1 = phead1->pNext;
	}
	while (phead2)
	{
		char val = phead2->val + remain;
		tailInSert(ppHeadRes, ppTailRes, val);
		phead2 = phead2->pNext;
	}
	if (remain == 1)
	{
		tailInSert(ppHeadRes, ppTailRes, '1');
		//headInSert(ppHeadRes, ppTailRes, '1');
	}	//就可以不用reverse
	reverse(ppHeadRes);
}

int compare(pList_t phead1, pList_t phead2)
{
	pList_t pivot1 = phead1;
	pList_t pivot2 = phead2;
	int length1 = 0;
	int length2 = 0;
	while (pivot1)
	{
		length1++;
		pivot1 = pivot1->pNext;
	}
	while (pivot1)
	{
		length2++;
		pivot2 = pivot2->pNext;
	}
	if (length1 > length2)
	{
		return 1;
	}
	else if (length1<length2)
	{
		return -1;
	}
	else//长度相等， 
	{
		pList_t pivot1 = phead1;
		pList_t pivot2 = phead2;
		while(pivot1)
		{
			if (pivot1->val > pivot2->val)
			{
				return 1;
			}
			else if (pivot1->val<pivot2->val)
			{
				return -1;
			}
			else
			{
				pivot1 = pivot1->pNext;
				pivot2 = pivot2->pNext;
			}
		}
		return 0;
	}
	return 0;
}

void reverse(pList_t* pphead)
{
	if (*pphead && (*pphead)->pNext)
	{
		pList_t pCur = (*pphead)->pNext;
		pList_t pAfter;
		(*pphead)->pNext = NULL;
		while (pCur)
		{
			pAfter = pCur->pNext;
			pCur->pNext = *pphead;
			*pphead = pCur;
			pCur = pAfter;
		}
	}
}

void minusPos(pList_t phead1, pList_t phead2, pList_t* ppHeadRes, pList_t* ppTailRes)
{
	reverse(&phead1);
	reverse(&phead2);
	int remain = 0;
	while (phead1 && phead2)
	{
		char val = phead1->val - phead2->val + remain - '0';
		if (val < '0')
		{
			val += 10;
			remain = -1;
		}
		else
		{
			remain = 0;
		}
		tailInSert(ppHeadRes, ppTailRes, val);
		phead1 = phead1->pNext;
		phead2 = phead2->pNext;
	}
	while (phead1)
	{
		char val = phead1->val + remain;
		tailInSert(ppHeadRes, ppTailRes, val);
		phead1 = phead1->pNext;
	}
	reverse(ppHeadRes);
	while ((*ppHeadRes)->val=='0')
	{
		*ppHeadRes = (*ppHeadRes)->pNext;
	}//省略数字前面的0
}