#include "sort.h"
int compare(const void* left,const void* right)
{
	int* p1=(int*)left;
	int* p2=(int*)right;
	return *p1-*p2;
}
int main()
{
	int i;
	int *arr=(int*)malloc(N*sizeof(int));
	time_t start,end;
	srand(time(NULL));    
	for( i = 0; i <N; i++ )     
	{
		arr[i]=rand()%100; 
	}
	arrPrint(arr);
	start=time(NULL);
	//arrSelect(arr);
	//arrInsert(arr);
	//arrShell(arr);
	//arrQuick(arr,0,N-1);
	//qsort(arr,N,sizeof(int),compare);
	//heapSort(arr);
	countSort(arr);
	end=time(NULL);
	arrPrint(arr);
	
	//printf("use time=%d\n",end-start);
	system("pause");
}