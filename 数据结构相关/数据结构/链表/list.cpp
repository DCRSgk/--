#include"myLibrary.h"
void headInSert(pStudent_t* ppHead, pStudent_t* ppTail, int val)
{
	pStudent_t pNew = (pStudent_t)calloc(1, sizeof(Student_t));
	pNew->num = val;

}	
void ListPrint(pStudent_t pHead) //ÒÀ´Î´òÓ¡
{
	pStudent_t	p = pHead;
	while (p != NULL)
	{
		printf("%4d\n", p->num);
		cout << "-------------------------------------------------------------------" << endl;
		p = p->pNext;
	}
}