#include"stack.h"
void initStack(pstack_t stack)  //³õÊ¼»¯Õ»
{
	memset(stack, 0, sizeof(stack_t));
}
void pop(pstack_t stack) //µ¯Õ»
{
	
	if (!stack->size)
	{
		printf("stack is empty");
	}
	pNode_t pCar;
	pCar = stack->phead;
	stack->phead = pCar.pNext;
	free(pCar);
	pCar = NULL;
}
void push(pstack_t stack, int val)
{
	pNode_t pNew = (pNode_t)calloc(1, sizeof(Node_t));
	pNew->val = val;
	pNew->pNext = stack->phead;
	stack->phead = pNew;
	stack->size++;
}//½øÕ»
int top(pstack_t stack) //
{
	if (!stack->size)
	{
		printf("stack is empty");
	}

}
int size(pstack_t stack);
int empty(pstack_t stack);