#include"sort.h"
void arrPrint(int* arr)
{
	for (int i = 0; i < N; i++)
	{
		printf("%3d", arr[i]);
	}
	printf("\n");
}
void arrSelect(int* arr)
{
	int Maxpots;
	for (int i = 0; i < N; i++)
	{
		Maxpots = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[Maxpots]) //改成小于则逆序输出
			{
				Maxpots = j;
			}
		}
		swap(arr[Maxpots], arr[i - 1]);
	}
}
void arrInsert(int* arr)
{
	int insertValue = 0;
	int j;
	for (int i = 0; i < N; i++)
	{
		insertValue = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insertValue)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = insertValue; //在找到插入位置之后再放入insertValue的值
	}
}
void arrShell(int* arr)
{
	int i, j, insertValue, gap;
	for (gap = N >> 1; gap > 0; gap >>= 1) //记忆
	{
		for (int i = gap; i < N; i++)
		{
			insertValue = arr[i];
			for (j = i - gap; j >= 0; j-=gap)
			{
				if (arr[j] > insertValue)
				{
					arr[j + gap] = arr[j];
				}
				else
				{
					break;
				}
			}
			arr[j + gap] = insertValue; //在找到插入位置之后再放入insertValue的值
		}

	}

}
int partition(int* arr, int left, int right)
{
	int i = left;
	int k = left;
	for (i = left; i < right; i++)
	{
		if (arr[right] > arr[i])
		{
			swap(arr[i], arr[k]);
			k++;
		}
	}
	swap(arr[k], arr[right]);
	return k;
}
void arrQuickSert(int* arr,int left, int right)
{
	int pivot;
	if (left<right)
	{
		pivot = partition(arr, left, right);
		arrQuickSert(arr, left,pivot - 1);
		arrQuickSert(arr, pivot - 1, right);
	}
} 
