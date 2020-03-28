#include"queue.h"
int main()
{
	ElemType e;
	SqQueue_t Q;
	initQueue(&Q);
	enQueue(&Q, 10);
	deQueue(&Q, e);
}