#include"sort.h"
int compare(const void* left, const void* right)
{
	int* p1 = (int*)left;
	int* p2 = (int*)right;
	return *p1 - *p2;
}
int main()
{
	int arr[N]; //�������ݵ�ʱ�򲻿���
	//int* arr = (int*)malloc(N * sizeof(int));
	srand(time_t(NULL)); //���������
	time_t start, end;
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}
	cout << "ԭ����Ϊ" << endl;
	arrPrint(arr);
	cout << "------------------------------" << endl;
	start = time(NULL);
	//arrSelect(arr);//ѡ������
	//arrInsert(arr);  //��������
	//arrShell(arr);
	//arrQuickSert(arr, 0, N - 1);
	qsort(arr, N, sizeof(int),compare);
	end = time(NULL);
	//cout << "�����Ϊ" << endl;
	//cout << "------------------------------" << endl;
	//arrPrint(arr);
	printf("use time %d", end - start);

	return 0;
}