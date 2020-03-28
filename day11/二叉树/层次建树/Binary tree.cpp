#include"Binary tree.h"
void proOrder(pNode_t root)//根左右
{
	if (root) 
	{
		putchar(root->c);
		proOrder(root->pleft);
		proOrder(root->pright);
	}
}//前序遍历
void midOrder(pNode_t root)//左根右
{
	if (root)
	{
		midOrder(root->pleft);
		putchar(root->c);
		midOrder(root->pright);
	}
}
void lastOrder(pNode_t root) //左右根
{
	if (root)
	{
		lastOrder(root->pleft);
		lastOrder(root->pright);
		putchar(root->c);
	}
}//后序遍历
void bulidBinaryTree(pNode_t* treeroot, pQueue_t*qHead, pQueue_t*qTail, ElemType val)
{
	pNode_t treeNew = (pNode_t)calloc(1, sizeof(Node_t));
	pQueue_t queNew = (pQueue_t)calloc(1, sizeof(Queue_t));
	pQueue_t queCur = *qHead;
	treeNew->c = val;
	queNew->insertPos = treeNew;
	if (NULL == *treeroot)
	{
		*treeroot = treeNew;
		*qHead = queNew;
		*qTail = queNew;
	}
	else
	{
		(*qTail)->pNext = queNew;
		*qTail = queNew;
		if (NULL==(*qHead)->insertPos->pleft)
		{
			(*qHead)->insertPos->pleft = treeNew;
		}
		else if (NULL==(*qHead)->insertPos->pright)
		{
			queCur->insertPos->pright = treeNew;
			*qHead = queCur->pNext;
			free(queCur);
			queCur = NULL;
		}
	}
	

}