#include"myLibrary.h"
void ListDelete(pStudent_t* pphead, student** ppTail, int deleteNum)
{
	pStudent_t pCur = *pphead;
	pStudent_t pPre = *pphead;
	if (pCur == NULL) {
		printf("List is empty\n");
	}
	else if (deleteNum == pCur->num) //���ɾ������ͷ�ڵ�
	{
		(*pphead) = pCur->pNext;
		free(pCur);
		pCur = NULL;
		if (NULL == *pphead) //���ֻ��һ���ڵ�
		{
			*ppTail = NULL;
		}
	}
	else
	{
		while (pCur)
		{
			if(pCur->num=deleteNum)
			{
				pPre->pNext = pCur->pNext;
				//ǰָ��ָ��ɾ����next
				break;
			}
			pPre = pCur;
			pCur = pCur->pNext;
		}
		if (NULL == pCur)
		{
			printf("don find");
			return;
		}
		if (pCur == *ppTail)
		{
			*ppTail = pPre;
		}
	}

}
void ListMdify(pStudent_t phead, int num, float score)
{
	while (phead)
	{
		if (phead->num == num)
		{
			phead->score = score;
		}
		phead->pNext
	}
}