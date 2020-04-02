#include "sort.h"

void arrPrint(int *arr)
{
	int i;
	for( i = 0; i <N; i++)     
	{
		printf("%3d",arr[i]);
	}
	printf("\n");
}

void arrSelect(int *arr)
{
	int i,j,maxPos;
	for(i=N;i>1;i--)//外层控制无序数数目
	{
		maxPos=0;
		for(j=1;j<i;j++)
		{
			if(arr[j]<arr[maxPos])
			{
				maxPos=j;
			}
		}
		SWAP(arr[maxPos],arr[i-1]);
	}
}

void arrInsert(int *arr)
{
	int i,j,insertValue;
	for(i=1;i<N;i++)
	{
		insertValue=arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(arr[j]>insertValue)
			{
				arr[j+1]=arr[j];
			}else{
				break;
			}
		}
		arr[j+1]=insertValue;
	}
}

void arrShell(int *arr)
{
	int i,j,insertValue,gap;
	for(gap=N>>1;gap>0;gap>>=1)
	{
		for(i=gap;i<N;i++)
		{
			insertValue=arr[i];
			for(j=i-gap;j>=0&&arr[j]>insertValue;j=j-gap)
			{
				arr[j+gap]=arr[j];
			}
			arr[j+gap]=insertValue;
		}
	}
}

int partition(int *arr,int left,int right)
{
	int i,k;
	for(i=left,k=left;i<right;i++)
	{
		if(arr[right]>arr[i])
		{
			SWAP(arr[i],arr[k]);
			k++;
		}
	}
	SWAP(arr[k],arr[right]);
	return k;
}
void arrQuick(int *arr,int left,int right)
{
	int pivot;
	if(left<right)
	{
		pivot=partition(arr,left,right);
		arrQuick(arr,left,pivot-1);
		arrQuick(arr,pivot+1,right);
	}
}

void heapSort(int* arr)
{
	for (int i = N / 2 - 1; i >= 0; i--)
	{
		adjustMaxheap(arr, i, N); //调成大根堆
	}
	SWAP(arr[0], arr[N - 1]);
	for (int i = N - 1; i > 1; i--)
	{
		adjustMaxheap(arr, 0, i);
		SWAP(arr[0], arr[i - 1]);
	}
}

void adjustMaxheap(int* arr, int adjuetPos, int arrlen)
{
	int dad = adjuetPos;
	int son = 2 * dad + 1;
	while (son<arrlen)
	{
		if (son + 1 < arrlen && arr[son] < arr[son + 1]) //说明有右子节点
		{
			son++;
		}
		if (arr[dad] < arr[son])  //如果子节点大于父节点，则直接交换
		{
			SWAP(arr[dad], arr[son]);
			dad = son;
			son = 2 * dad + 1;
		}
		else
		{
			break;
		}
	}
}

void countSort(int *arr)
{
	int i,j;
	int count[100] = {0};
	for (int i = 0; i < N; i++)
	{
		count[arr[i]]++;
	}
	int k = 0;
	for (j = 0; j < 100; j++) //要填入值的范围
	{
		for (int i = 0; i < count[j]; i++)
		{
			arr[k] = j;
			k++;
		}
	}
}