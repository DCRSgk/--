#include"stack.h"
int main()
{
	stack_t stack; //����ʹ��ջ�ռ�
	initStack(&stack);
	push(&stack, 5);
	push(&stack, 10);
}