#include"myLIbrary.h"
int compare(const void* p1, const void* p2);
int main()
{
	
	int* Arr = (int*)malloc(N * sizeof(int));
	srand(time_t(NULL));
	time_t start, end;
	for (int i = 0; i < N; i++)
	{
		Arr[i] = rand();
		//cout << Arr[i] << " ";
	}
	//cout << endl;
	cout << "------------------------------" << endl;
	start = time(NULL);
	//qsort(Arr, N, sizeof(int), compare);
	//shellSort(Arr);
	//selectSort(Arr); //��˯���� ���
	quickSort(Arr, 0, N - 1);
	//quickSort2(Arr, 0, N - 1); //���� ������Ϣ���������쳣: ��ȡ����Ȩ�޳�ͻ��
	end = time(NULL);
	printf("use time %d", (int)end - (int)start); 

}
int compare(const void* left, const void* right)
{
	int* p1 = (int*)left;
	int* p2 = (int*)right;
	return *p1 - *p2;
}
