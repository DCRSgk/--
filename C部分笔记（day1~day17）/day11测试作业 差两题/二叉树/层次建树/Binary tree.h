#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef char ElemType;
typedef struct node_t
{
	ElemType c;
	struct node_t* pleft;
	struct node_t* pright;

}Node_t, * pNode_t;

typedef struct queue_t
{
	pNode_t insertPos;
	struct queue_t* pNext;
}Queue_t, * pQueue_t;
void proOrder(pNode_t root);
void midOrder(pNode_t root);
void lastOrder(pNode_t root);
void bulidBinaryTree(pNode_t* treeroot, pQueue_t*, pQueue_t*, ElemType);
