#include"myLIbrary.h"
//��Ҫ���Զ�����Ĳ���Ч�����޸�ͷ�ļ����N��ֵ
//��дһ���Զ�����+�Զ��жϵ�
int main()
{
	int Arr[N];
	srand(time(NULL));
	time_t start, end;
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		Arr[i] = rand() % 100;
	}
	cout << endl;
	qsort(Arr, N, sizeof(int), compare);
	printf("�����ҵ�����Ϊ\n");
	for (int i = 0; i < N; i++)
	{
		printf("%3d",Arr[i]);
	}
	cout << endl;
	cout << "������һ���ϱ����е�����" << endl;
	int r;
	cin >> r;
	if (int i= binarySearch(Arr, r))
	{
		printf("Ҫ���ҵ�����Ϊ%d�ڵ�%d��\n", r, i);
	}
	else
	{
		printf("�Һ���û���ҵ���.jpg\n");
	}
	binarySearch(Arr,Arr[r]);

}