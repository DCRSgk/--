#include "myLIbrary.h"
void shellSort(int* arr)
{
	int i, j, insertValue, gap;
	for (gap = N >> 1; gap > 0; gap >>= 1)
	{
		for (int i = gap; i < N; i++)
		{
			insertValue = arr[i];
			for (j = i - gap; j >= 0; j -= gap)
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
			arr[j + gap] = insertValue;
			//在找到插入位置之后再放入insertValue的值
		}
	}
}
void selectSort(int* Arr)
{
	int Minpots;
	for (int i = 0; i < N - 1; i++)
	{
		Minpots = i; //每次循环重置Maxpots的值
		for (int j = 1; j < i; j++)
		{
			if (Arr[Minpots] > Arr[j])
			{
				Minpots = j;
			}
			swap(Arr[i - 1], Arr[Minpots]);
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
void quickSort(int* arr, int left, int right)
{
	int pivot;
	if (left < 0 || right >= N)
	{
		cout << "这活我没法接，请输入正确的边界值" << endl;
		return;
	}
	if (left < right) //递归出口
	{
		pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot - 1, right);
	}
}
void quickSort2(int* arr, int left, int right)
{
	if (left >= right) return;//递归出口
	int i, j, temp;
	i = left;
	j = right;
	int pivot;
	pivot = arr[i];
	while (i < j) 	//左右哨兵握手时候退出循环
	{
		while (i < j && arr[j] >= pivot)
		{
			j--;
		}
		while (i < j && arr[i] <= pivot)
		{
			i++;
		}
		if (i < j) //swap函数
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//重置哨兵值
	arr[left] = arr[i];
	arr[i] = pivot;
	quickSort2( arr, left, i - 1);
	quickSort2( arr,i-1, right);
}

