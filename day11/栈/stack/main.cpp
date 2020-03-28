#include"stack.h"
int main()
{
	stack_t stack; //优先使用栈空间
	initStack(&stack);
	push(&stack, 5);
	push(&stack, 10);
}