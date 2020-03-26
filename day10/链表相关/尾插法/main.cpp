#include"myLibrary.h"
int main() 
{
	Student_t sArr[5];
	int a[5] = { 0 };
	pStudent_t pHead = NULL;
	pStudent_t pTail = NULL;
	
	for (int i = 0; i < 5; i++)
	{
		cin >> sArr[i].num >> sArr[i].name >> sArr[i].cham >> sArr[i].biology
			>> sArr[i].phy;
		/*scanf_s("%d %s %d %d %d", &sArr[i].num, sArr[i].name, &sArr[i].cham, &sArr[i].biology,
			&sArr[i].phy);*/
		sArr[i].score = sArr[i].cham + sArr[i].biology, +sArr[i].phy;
		numSert(&pHead, &pTail, sArr[i]);
	}
	ListPrint(pHead);
}