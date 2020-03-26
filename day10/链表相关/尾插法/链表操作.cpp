#include"myLibrary.h"
void bobble(student a)
{
	int tmp;
	int len = sizeof(a) / sizeof(int);
	for (int i = 0; i < len; i++) {
		
	}
}

void numSert(pStudent_t* ppHead, Student_t** ppTail, Student_t val) //头插法实现按照学号建立链表
{
	pStudent_t pCur,pPre;
	pStudent_t pNew = (pStudent_t)calloc(1, sizeof(Student_t));
	pCur = *ppHead;
	pPre = *ppHead;
	pNew->num = val.num;
	if (*ppHead == NULL) //判空
	{
		*ppHead = pNew;
		*ppTail = pNew;
	}
	else if((val.num)<(pCur->num)) //头插法
	{
			pNew->pNext = pCur;
			*ppHead = pNew;
	}
	else
	{
		while (pCur)
		{
			if (pCur->num > val.num)
			{
				pPre->pNext = pNew;
				pNew->pNext = pCur;
				break;
			}
			pPre = pCur;
			pCur = pCur->pNext;
		}
		if(NULL==pCur) //尾插法
		{
			pPre->pNext = pNew;
			*ppTail = pNew;
		}
	}
}
void ListPrint(pStudent_t pHead) //依次打印
{
	while (pHead != NULL)
	{
		printf("%4d %s %4d %4d %4d %4d\n", pHead->num, pHead->name, pHead->cham,
			pHead->biology, pHead->phy, pHead->score);
		cout << "-------------------------------------------------------------------" << endl;
		pHead = pHead->pNext;
	}
}
void ListTailInSert(pStudent_t* ppHead, Student_t** ppTail, int val)
{
	pStudent_t pNew = (pStudent_t)calloc(1, sizeof(Student_t));
	pNew->num = val;
	if (NULL == *ppTail) //判空 如果空则直接将尾指针和头指针指向new；
	{
		*ppHead = pNew;
		*ppTail = pNew;
	}
	else
	{
		(*ppTail)->pNext = pNew;
		*ppTail = pNew;
	}
} //尾插法 
