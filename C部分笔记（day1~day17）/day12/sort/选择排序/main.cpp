#include"sort.h"
int compare(const void* left, const void* right)
{
	int* p1 = (int*)left;
	int* p2 = (int*)right;
	return *p1 - *p2;
}
int main()
{
	int arr[N]; //过大数据的时候不可用
	//int* arr = (int*)malloc(N * sizeof(int));
	srand(time_t(NULL)); //随机数种子
	time_t start, end;
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}
	cout << "原数据为" << endl;
	arrPrint(arr);
	cout << "------------------------------" << endl;
	start = time(NULL);
	//arrSelect(arr);//选择排序
	//arrInsert(arr);  //插入排序
	//arrShell(arr);
	//arrQuickSert(arr, 0, N - 1);
	qsort(arr, N, sizeof(int),compare);
	end = time(NULL);
	//cout << "排序后为" << endl;
	//cout << "------------------------------" << endl;
	//arrPrint(arr);
	printf("use time %d", end - start);

	return 0;
}