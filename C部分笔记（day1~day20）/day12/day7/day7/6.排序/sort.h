#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 100;
#define SWAP(a,b) {int tmp;tmp=a;a=b;b=tmp;}
void arrPrint(int*);
void arrSelect(int*);
void arrInsert(int*);
void arrShell(int*);
void arrQuick(int *arr,int left,int right);
void heapSort(int* arr);
void adjustMaxheap(int* arr, int adjuetPos, int arrlen);
void countSort(int* arr);
