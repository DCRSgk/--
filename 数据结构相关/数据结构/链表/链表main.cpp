#include "list.cpp"
int main()
{
	Student_t arr[5];
	pStudent_t phead = NULL;
	pStudent_t ptail = NULL;
	for(int i=0;i<5;i++)
	{
		cin >> arr[i].num;
		headInSert(&phead, &ptail, arr[i].num);
	}
	
	ListPrint()

}