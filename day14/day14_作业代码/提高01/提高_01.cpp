#include"myLIbrary.h"
int binarySearch(int* arr, int key)
{
	int left = 0;
	int right = N-1;
	while (left<=right)
	{
		int mid;
		mid = (left + right) / 2;
		if (arr[mid] = key)
		{
			return mid;
		}
		else if (arr[mid]>key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return 0;
}

int compare(const void* left, const void* right)
{
	int* p1 = (int*)left;
	int* p2 = (int*)right;
	return *p1 - *p2;
}