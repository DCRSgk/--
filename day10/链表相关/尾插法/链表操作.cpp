#include"myLibrary.h"
void bobble(student a)
{
	int tmp;
	int len = sizeof(a) / sizeof(int);
	for (int i = 0; i < len; i++) {
		
	}
}

void numSert(pStudent_t* ppHead, Student_t** ppTail, Student_t val) //ͷ�巨ʵ�ְ���ѧ�Ž�������
{
	pStudent_t pCur,pPre;
	pStudent_t pNew = (pStudent_t)calloc(1, sizeof(Student_t));
	pCur = *ppHead;
	pPre = *ppHead;
	pNew->num = val.num;
	if (*ppHead == NULL) //�п�
	{
		*ppHead = pNew;
		*ppTail = pNew;
	}
	else if((val.num)<(pCur->num)) //ͷ�巨
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
		if(NULL==pCur) //β�巨
		{
			pPre->pNext = pNew;
			*ppTail = pNew;
		}
	}
}
void ListPrint(pStudent_t pHead) //���δ�ӡ
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
	if (NULL == *ppTail) //�п� �������ֱ�ӽ�βָ���ͷָ��ָ��new��
	{
		*ppHead = pNew;
		*ppTail = pNew;
	}
	else
	{
		(*ppTail)->pNext = pNew;
		*ppTail = pNew;
	}
} //β�巨 
