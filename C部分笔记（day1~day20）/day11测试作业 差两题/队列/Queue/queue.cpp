#include"queue.h"
void initQueue(SqQueue_t*queue)
{
	queue->front = queue->rear = 0;
	//头尾指针相等且等于0
}  //初始化
void enQueue(SqQueue_t* queue, ElemType x)
{
	if ((queue->rear + 1) % Maxsize == queue->front)
	{
		cout << "queue is full" << endl;
		return;
	}
	queue->dada[queue->rear] = x;
	queue->rear = (queue->rear + 1) % Maxsize;
}//进队
void deQueue(SqQueue_t* queue, ElemType*x)
{
	if (queue->front = queue->rear)
	{
		cout << "queue is empty" << endl;
		return;
	}
	*x = queue->dada[queue->front] ;
	queue->front = (queue->front + 1) % Maxsize;
}//出队
