#include"myList.h"

void ListDelete(pList_t* ppHead, List_t** ppTail, int deleteNum)
{
	pList_t pCur = *ppHead;
	pList_t pPre = *ppHead;	
	if (pCur == NULL)
	{
		cout << "���һ�ζ�û����" << endl;
		return;
	}
	else if(deleteNum==pCur->num)
	{//ɾ����λ��ǡ��Ϊͷ�ڵ�
		*ppHead = pCur->pNext;
		if (NULL==*ppHead) //���ǡ��ֻ��һ��Ԫ������������ֵ
		{
			*ppTail == NULL;
		}
	}
	else
	{
		while (pCur)
		{
			if (deleteNum == pCur->num)
			{
				pPre->pNext = pCur->pNext;
				cout << "�ɹ�ɾ��" << deleteNum << endl;
				break;
			}
			pPre = pCur;//��ָ�����ǰָ��
			pCur = pCur->pNext;//ǰָ����ǰ��һ��
		}
		if (NULL == pCur)
		{
			cout << "���" << deleteNum << "��û��" << endl;
			return;
		}
		if (pCur == *ppTail)
		{//���ɾ������δ�ڵ�
			*ppTail = pPre;
		}
	}
	free(pCur);
	pCur = NULL;
}
void print(pList_t p)
{
	pList_t pCur = p;
	while (pCur)
	{
		printf("%3d %s %3.2d", pCur->num, pCur->name, pCur->cham);
		pCur = pCur->pNext;
	}
}
pList_t currentList(pList_t phead)
{
	pList_t newList;
	stack<pList_t> stack1;
	while (phead)
	{
		stack1.push(phead);
		phead = phead->pNext;
	}
	newList = phead;
	while (!stack1.empty)
	{
		phead->pNext = stack1.pop;
		phead = phead->pNext;
		stack1.pop;
	}
	phead->pNext = NULL;
	return newList;
}
void getLast4th(pList_t head)
{
	pList_t fast = head;
	pList_t low = head;
	int step = 4;
	while (step)
	{
		fast = fast->pNext;
		step--;
	}
	if (fast == NULL)
	{
		cout << "������С���Ļ���ɶ�������İ�" << endl;
	}
	else
	{
		while (fast)
		{   //��ͷ����
			fast = fast->pNext;
			low = low->pNext;
		}
	}
	cout << "�벻����" << low->num << "���ǵ������ĸ�" << endl;
}
bool getRing(pList_t head)
{
	pList_t fast = head;
	pList_t low = head;
	int step = 2;
	while (step)
	{
		fast = fast->pNext;
		step--;
	}
	if (fast == NULL)
	{
		cout << "�������²����л���������" << endl;
	}
	else
	{
		while (low) //
		{
			if (low == fast) return 1;
			else
			{
				fast = fast->pNext;
				low = low->pNext;
			}
		}
		return 0;

	}


}