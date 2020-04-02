#include "list.h"
//����ͷ�巨
void listHeadInsert(pStudent_t *ppHead,Student_t **ppTail,int val)
{
	pStudent_t pNew=(pStudent_t)calloc(1,sizeof(Student_t));
	pNew->num=val;
	if(NULL==*ppHead)//�ж������Ƿ�Ϊ��
	{
		*ppHead=pNew;
		*ppTail=pNew;
	}else{
		pNew->pNext=*ppHead;
		*ppHead=pNew;
	}
}
//�����ӡ
void listPrint(pStudent_t pHead)
{
	while(pHead)
	{
		printf("%3d %5.2f\n",pHead->num,pHead->score);
		pHead=pHead->pNext;
	}
}
//����β�巨
void listTailInsert(pStudent_t *ppHead,Student_t **ppTail,int val)
{
	pStudent_t pNew=(pStudent_t)calloc(1,sizeof(Student_t));
	pNew->num=val;
	if(NULL==*ppTail)
	{
		*ppHead=pNew;
		*ppTail=pNew;
	}else{
		(*ppTail)->pNext=pNew;
		*ppTail=pNew;
	}
}
//�����������
void listSortInsert(pStudent_t *ppHead,Student_t **ppTail,int val)
{
	pStudent_t pNew=(pStudent_t)calloc(1,sizeof(Student_t));
	pStudent_t pCur,pPre;
	pCur=pPre=*ppHead;
	pNew->num=val;
	if(NULL==pCur)//�ж������Ƿ�Ϊ��
	{
		*ppHead=pNew;
		*ppTail=pNew;
	}else if(val<pCur->num)//ͷ�巨
	{
		pNew->pNext=*ppHead;
		*ppHead=pNew;
	}else{
		while(pCur)//���뵽�м�
		{
			if(pCur->num>val)
			{
				pPre->pNext=pNew;
				pNew->pNext=pCur;
				break;
			}
			pPre=pCur;
			pCur=pCur->pNext;
		}
		if(NULL==pCur)//��ʱ��Ҫ���뵽β��
		{
			pPre->pNext=pNew;
			*ppTail=pNew;
		}
	}
}
//�����ɾ��
void listDelete(pStudent_t *ppHead,Student_t **ppTail,int deleteNum)
{
	pStudent_t pCur=*ppHead,pPre;
	pPre=pCur;
	if(NULL==pCur)
	{
		printf("List is empty\n");
		return;
	}else if(pCur->num==deleteNum)//ɾ������ͷ��
	{
		*ppHead=pCur->pNext;
		if(NULL==*ppHead)
		{
			*ppTail=NULL;
		}
	}else{
		while(pCur)//ɾ�������м����β��
		{
			if(pCur->num==deleteNum)
			{
				pPre->pNext=pCur->pNext;
				break;
			}
			pPre=pCur;
			pCur=pCur->pNext;
		}
		if(NULL==pCur)//û���ҵ���Ӧ���
		{
			printf("Don't find deleteNum\n");
			return;
		}
		if(pCur==*ppTail)
		{
			*ppTail=pPre;
		}	
	}
	free(pCur);
	pCur=NULL;
}

void listModify(pStudent_t pHead,int num,float score)
{
	while(pHead)
	{
		if(pHead->num==num)
		{
			pHead->score=score;
			break;
		}
		pHead=pHead->pNext;
	}
	if(NULL==pHead)
	{
		printf("Don't find modify num\n");
	}
}