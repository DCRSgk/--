#include"myLibrary.h"
account user[1024];

int userCount = 0;
void loadUser()
{
	FILE* fp;
	fp = fopen("stu_account.txt", "r+");
	while (fscanf(fp, "%s and %s", user[userCount].id, 
		user[userCount].passport)!=EOF)
	{
		userCount++;
	}
	fclose(fp);
}

void saveUser()
{
	FILE *fp;
	fp = fopen("stu_account.txt", "r+");
	for (int i = 0; i <= userCount; i++)
	{
		fprintf(fp, "%s and %s\n", user[i].id,user[i].passport);
	}
	fclose(fp);
}

void loginMenu()	//登录界面
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
			signIn(); break;
		case 3:
			//reSetPassport(); break;
		default:
			system("cls");
			loginMenu();
		}
	}
}




void signUp()
{
	
	int i; 
	char str[20];
	char c;
	FILE* fp;
	fp = fopen("stu_account.txt", "r+");
	system("cls");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\tPlease enter your account:");
	scanf("%s", str);
	if (strlen(str) > 18)
	{
		printf("\t\t\tUsername is not available\n\n\t\t\t");
		system("pause");
		system("cls");
		signUp();
		return;
	}
	for (i = 0; i < userCount; i++) //检查重名
	{
		if (strcmp(user[i].id, str) == 0)
		{
			printf("\t\t\tUsername is not available\n\n\t\t\t");
			system("pause");
			signUp();
			return;
		}
	}
	strcpy(user[i].id, str);
	printf("\t\t\tPlease enter your passport:");
	scanf("%s", str);
	strcpy(user[i].passport, str);
	printf("\t\t\tPlease enter your passport again:");
	scanf("%s", str);
	if (strcmp(str, user[i].passport) == !0)
	{
		printf("\t\t\tPlease try it again\n\n\t\t\t");
		system("pause");
		system("cls");
		signUp();
		return;
	}
	saveUser();
	printf("\t\t\tAccount application succeeded.\n\n\t\t\t");	
	system("pause");
	system("cls");
	loginMenu();
	return;
}

void signIn()
{
	int i = 0;
	int flag = 0;
	char str[50];
	system("cls");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\tPlease enter your account:");
	scanf("%s", str);
	for (i = 0; i <= userCount; i++)
	{
		if (strcmp(user[i].id, str) == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("\n\t\t\tNot find your account please sign up\n\n\t\t\t");
		system("pause");
		system("cls");
		loginMenu();
		return;
	}
	printf("\n\t\t\tPlease enter your passport:");
	for (int i = 0; i < 20; i++)
	{
		str[i] = _getch();
		if (str[i] == '\b')
		{
			printf("\b \b");
		}
		if (str[i] == '\r')
		{
			break;
		}
		printf("*");
	}
	while (strcmp(user[i].passport, str) != 0)
	{
		system("cls");
		printf("\n\t\t\tPlease enter your passport again:");
		scanf("%s", str);
	}
	printf("\n\t\t\tWelcome\t\t\t");
	printf("\n\t\t\tLoading...\t\t\t");
	printf("\n\t\t\tLoading...\t\t\t");
	system("pause");



}

void systemMenu1()    //管理员菜单
{
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\t\t\t\t                学生管理系统");
	printf("\n");
	printf("\n\t\t\t              1、   Add Student information");
	printf("\n\t\t\t              2、   Delete student information      ");
	printf("\n\t\t\t              3、   Update student information ");
	printf("\n\t\t\t              4、   Search student information ");
	printf("\n\t\t\t              5、   Add user account ");
	printf("\n\t\t\t              6、   Delete user information ");
	printf("\n\t\t\t              7、   Search user information ");
	printf("\n\t\t\t              8、   Exit ");
	printf("\n\t\t\t                        please enter your choice：");
	int i;
	while (1)
	{
		scanf("%d", &i);

		switch (i)
		{
		case 1:
			//signUp(); break;
		case 2:
			//signIn(); break;
		case 3:
			//reSetPassport(); break;
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		default:
			break;
		}
	}
}


void systemMenu2()    //学生菜单
{
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\t\t\t\t                学生管理系统");
	printf("\n");
	printf("\n\t\t\t              1、   Search student information ");
	printf("\n\t\t\t              2、   Exit ");
	printf("\n\t\t\t                        please enter your choice：");
	int i;
	while (1)
	{
		scanf("%d", &i);

		switch (i)
		{
		case 1:
			//signUp(); break;
		case 2:
			//signUp(); break;	
		default:
			break;
		}
	}
}
