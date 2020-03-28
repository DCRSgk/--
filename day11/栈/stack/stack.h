#include<iostream>
#include<cstdio>
#include<string>
typedef struct tag
{
	int val;
	struct tag* pNext;
}Node_t, * pNode_t;
typedef struct
{
	pNode_t phead;
	int size;
}stack_t, * pstack_t;
void initStack(pstack_t stack);
void pop(pstack_t stack );//µ¯Õ»
void push(pstack_t, int);
int top(pstack_t stack);//½ö·µ»ØÕ»¶¥ÔªËØ
int size(pstack_t stack);
int empty(pstack_t stack);