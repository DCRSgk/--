#include"Binary tree.h"
constexpr auto N = 10;;
int main()
{
	ElemType val;
	pNode_t treeRoot = NULL;
	pQueue_t queHead = NULL;
	pQueue_t queTail = NULL;
	//while(scanf("%c", &val) != EOF)
	//{
	//	if (val == '\n') break;
	//	bulidBinaryTree(&treeRoot, &queHead, &queTail,val);
	//}
	int j = 0;
	ElemType c[] = "ABCDEFGHIJ";
	pNode_t p[N];
	for (int i = 0; i < N;i++)
	{
		p[i] = (pNode_t)calloc(1, sizeof(Node_t));
		p[i]->c = c[i];
	}
	for (int i = 1; i < N; i++)
	{
		if (NULL == p[j]->pleft) {
			p[j]->pleft = p[i];
		}
		else if(NULL ==p[j]->pright)
		{
			p[j]->pright = p[i];
			j++;
		}
	}
	
	proOrder(p[0]); //前序遍历
	cout << "-------------------------" << endl;
	midOrder(p[0]); //中序遍历
	cout << "-------------------------" << endl;
	lastOrder(p[0]);//后序遍历
	cout << "-------------------------" << endl;

}