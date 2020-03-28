#include<cstdio>
#include<cstring>
#include <iostream>
#define Maxsize 5
using namespace std;
typedef int ElemType;
typedef struct
{
	ElemType dada[Maxsize];
	int front, rear;
}SqQueue_t;
void initQueue(SqQueue_t*);
void enQueue(SqQueue_t*, ElemType);
void deQueue(SqQueue_t*, ElemType);

