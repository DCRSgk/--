#include"myList.h"

void ListDelete(pList_t* ppHead, List_t** ppTail, int deleteNum)
{
	pList_t pCur = *ppHead;
	pList_t pPre = *ppHead;	
	if (pCur == NULL)
	{
		cout << "真的一滴都没有了" << endl;
		return;
	}
	else if(deleteNum==pCur->num)
	{//删除的位置恰好为头节点
		*ppHead = pCur->pNext;
		if (NULL==*ppHead) //如果恰好只有一个元素则清空链表的值
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
				cout << "成功删除" << deleteNum << endl;
				break;
			}
			pPre = pCur;//后指针等于前指针
			pCur = pCur->pNext;//前指针往前走一格
		}
		if (NULL == pCur)
		{
			cout << "这个" << deleteNum << "真没有" << endl;
			return;
		}
		if (pCur == *ppTail)
		{//如果删除的是未节点
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
		cout << "链表长度小于四还求啥倒数第四啊" << endl;
	}
	else
	{
		while (fast)
		{   //齐头并进
			fast = fast->pNext;
			low = low->pNext;
		}
	}
	cout << "想不到吧" << low->num << "就是倒数第四个" << endl;
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
		cout << "两个以下不会有环，别找了" << endl;
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