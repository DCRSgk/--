#include "list.h"

int main()
{
	pStudent_t phead=NULL,ptail=NULL;
	int num;
	float score;
	while(scanf("%d",&num)!=EOF)
	{
		//listHeadInsert(&phead,&ptail,num);
		//listTailInsert(&phead,&ptail,num);
		listSortInsert(&phead,&ptail,num);
	}
	listPrint(phead);
	//ˢ�±�׼���
	//while(printf("please input delete num:"),fflush(stdout),scanf("%d",&num)!=EOF)
	//{
	//	listDelete(&phead,&ptail,num);
	//	listPrint(phead);
	//}
	while(printf("please input modify num and score:"),fflush(stdout),scanf("%d%f",&num,&score)!=EOF)
	{
		listModify(phead,num,score);
		listPrint(phead);
	}
	system("pause");
}