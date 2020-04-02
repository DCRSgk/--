#include "list.h"
//链表头插法
void listHeadInsert(pStudent_t *ppHead,Student_t **ppTail,int val)
{
	pStudent_t pNew=(pStudent_t)calloc(1,sizeof(Student_t));
	pNew->num=val;
	if(NULL==*ppHead)//判断链表是否为空
	{
		*ppHead=pNew;
		*ppTail=pNew;
	}else{
		pNew->pNext=*ppHead;
		*ppHead=pNew;
	}
}
//链表打印
void listPrint(pStudent_t pHead)
{
	while(pHead)
	{
		printf("%3d %5.2f\n",pHead->num,pHead->score);
		pHead=pHead->pNext;
	}
}
//链表尾插法
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
//链表有序插入
void listSortInsert(pStudent_t *ppHead,Student_t **ppTail,int val)
{
	pStudent_t pNew=(pStudent_t)calloc(1,sizeof(Student_t));
	pStudent_t pCur,pPre;
	pCur=pPre=*ppHead;
	pNew->num=val;
	if(NULL==pCur)//判断链表是否为空
	{
		*ppHead=pNew;
		*ppTail=pNew;
	}else if(val<pCur->num)//头插法
	{
		pNew->pNext=*ppHead;
		*ppHead=pNew;
	}else{
		while(pCur)//插入到中间
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
		if(NULL==pCur)//这时就要插入到尾部
		{
			pPre->pNext=pNew;
			*ppTail=pNew;
		}
	}
}
//链表的删除
void listDelete(pStudent_t *ppHead,Student_t **ppTail,int deleteNum)
{
	pStudent_t pCur=*ppHead,pPre;
	pPre=pCur;
	if(NULL==pCur)
	{
		printf("List is empty\n");
		return;
	}else if(pCur->num==deleteNum)//删除的是头部
	{
		*ppHead=pCur->pNext;
		if(NULL==*ppHead)
		{
			*ppTail=NULL;
		}
	}else{
		while(pCur)//删除的是中间或者尾部
		{
			if(pCur->num==deleteNum)
			{
				pPre->pNext=pCur->pNext;
				break;
			}
			pPre=pCur;
			pCur=pCur->pNext;
		}
		if(NULL==pCur)//没有找到对应结点
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