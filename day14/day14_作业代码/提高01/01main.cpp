#include"myLIbrary.h"
//若要测试多个数的查找效率请修改头文件里的N的值
//向写一个自动排序+自动判断的
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
	printf("待查找的数据为\n");
	for (int i = 0; i < N; i++)
	{
		printf("%3d",Arr[i]);
	}
	cout << endl;
	cout << "请输入一个上表中有的数据" << endl;
	int r;
	cin >> r;
	if (int i= binarySearch(Arr, r))
	{
		printf("要查找的数据为%d在第%d个\n", r, i);
	}
	else
	{
		printf("我好像没有找到啊.jpg\n");
	}
	binarySearch(Arr,Arr[r]);

}