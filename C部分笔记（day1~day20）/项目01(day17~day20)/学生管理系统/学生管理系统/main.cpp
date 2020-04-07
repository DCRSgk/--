#include"myLibrary.h"
int main()
{
	pStudent_t phead = NULL;

	//loadUser();

	//printAccount();
	//systemMenu1();
	//systemMenu2();
	//loginMenu();
	loadStudent(&phead);
	addStudentInfo();


	printStudentInfo(phead);

	


error:
	system("pause");
}
