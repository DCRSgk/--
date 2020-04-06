#include"myList.h"
int main()
{
	List_t sArr[5] = { { 1001,"lilei",98.8 },{1002,"hanmeimei",99.5},{1007,"leelee",77},{1024,"otto",59}
		,{7777,"clearlove",43.96} };
	pList_t p[5];
	pList_t phead = p[0];
	pList_t ptail = p[4];
	for (int i = 0; i < 5; i++)
	{
		p[i] = &sArr[i];
	}
	int deleteNum;
	cin >> deleteNum;
	print(phead);
	ListDelete( &phead, &ptail, deleteNum);
	cout << "-------------------" << endl;
	print(phead);
}