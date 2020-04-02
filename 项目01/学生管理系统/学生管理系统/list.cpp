#include"myLibrary.h"
void systemMenu(void)
{
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\t\t\t\t                学生管理系统");
	printf("\n");
	printf("\n\t\t\t              1、Sign up for the system           ");
	printf("\n\t\t\t              2、Sign in to the system           ");
	printf("\n\t\t\t              3、If you Forgot password          ");
	printf("\n\t\t\t                        please enter your choice：");
	int i;
	int boom = 3;
	while (1)
	{
		scanf("%d", &i);

		switch (i)
		{
		case 1:
			signUp(); break;
		case 2:
			//signIn(); break;
		case 3:
			//reSetPassport(); break;
		default:
			break;
		}
	}
}

void signUp()
{
	user acc;
	char str[20];
	FILE* fp;
	int i;
	fp = fopen("stu_account.txt", "r+");
	system("cls");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\tPlease enter your account:");
	scanf("%s", str);
	for (int i = 0; i <= userCount; i++)
	{
		if(strcmp(user[i]))
	}
	strcpy(acc[userCount].id, str);
	printf("\n");
	printf("密码");
	printf("\n");
	memset(str, 0, sizeof(str));
	scanf("%s", str);
	strcpy(acc[userCount].passport, str);
	fprintf(fp, "%s %s 1", acc[userCount].id, acc[userCount].passport, acc[userCount].permission);
	fclose(fp);
	userCount++;



}



void headInSert(pStudent_t* pphead, pStudent_t* pptail, int val)
{
	pStudent_t pNew = (pStudent_t)calloc(1, sizeof(Student_t));
	pNew->num = val;
	if (*pphead == NULL)
	{
		*pphead = pNew;
		*pptail = pNew;
	}
	else
	{
		pNew->pNext = *pphead;
		*pphead = pNew;
	}
}

void tailInSert(pStudent_t* pphead, pStudent_t* pptail, int val)
{
	pStudent_t pNew = (pStudent_t)calloc(1, sizeof(Student_t));
	pNew->num = val;
	if (*pphead == NULL)
	{
		*pphead = pNew;
		*pptail = pNew;
	}
	else
	{
		(*pptail)->pNext = pNew; //->优先级比*高
		*pptail = pNew;
	}
}
