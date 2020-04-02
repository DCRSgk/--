#include"myLibrary.h"
int compareNum(const void* pleft, const void* pright)
{
	ptable_t p1;
	ptable_t p2;
	p1 = (ptable_t)pleft;
	p2 = (ptable_t)pright;
	return  p2 - p1;
}
int main()
{
	table_t Arr[N];
	srand(time(NULL));
	ptable_t phead = NULL;
	ptable_t ptail = NULL;
	for (int i = 0; i < N; i++)
	{
		Arr[i].num=rand() % 100;
		cout << Arr[i].num;
		cout << endl;
	}
	cout << "----" << endl;
	qsort(Arr, N, sizeof(table_t), compareNum);
	for (int i = 0; i < N; i++)
	{
		cout << Arr[i].num;
		cout << endl;
	}
}
void inList(ptable_t* pphead, ptable_t* pptail ,int val)
{
	ptable_t pNew = (ptable_t)calloc(1, sizeof(table_t));
	pNew->num = val;
	if (NULL == *pptail)
	{
		*pphead = pNew;
		*pptail = pNew;
	}
	else
	{
		(*pptail)->pNext = pNew;
		*pptail = pNew;
	}
}