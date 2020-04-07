#include"myLibrary.h"
account user[1024]; //数组存储
int userCount = 0;
Student_t student[1024];
int studentCount = 0;

void loadUser()
{
	FILE* fp;
	fp = fopen("stuAccount.txt", "r+");
	while (fscanf(fp, "%s %s and %c", user[userCount].id,
		user[userCount].passport, &user[userCount].role) != EOF)
	{
		userCount++;
	}
	fclose(fp);
}
void saveUser()
{
	FILE* fp;
	fp = fopen("stuAccount.txt", "r+");
	for (int i = 0; i <= userCount; i++)
	{
		fprintf(fp, "%s %s and %c\n", user[i].id, user[i].passport, user[i].role);
	}
	fflush(fp);
	fclose(fp);
}
void loadStudent()
{

	FILE* fp;
	fp = fopen("stuInfo.txt", "r+");
	int num;
	char gender[5];
	char name[20];
	float chem;
	float biology;
	float physical;
	float totalScore;
	while (fscanf(fp, "%d %s %s %f %f %f %f",
		&student[studentCount].num, student[studentCount].name, student[studentCount].gender,
		&student[studentCount].chem, &student[studentCount].biology,
		&student[studentCount].physical, &student[studentCount].totalScore) != EOF)
	{
		studentCount++;
	}
	fclose(fp);
}
void saveStudent()
{
	FILE* fp;
	int i = 0;
	fp = fopen("stuInfo.txt", "w");
	for (int i = 0; i <= studentCount; i++)
	{
		fprintf(fp, "%d %s %s %5.2f %5.2f %5.2f %5.2f\n", student[i].num,
			student[i].name, student[i].gender,
			student[i].chem, student[i].biology,
			student[i].physical, student[i].totalScore);
	}
	fflush(fp);
	fclose(fp);
}

void signUp()
{
	system("cls");
	int i;
	char str[20];
	char c;
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\tPlease enter your account:");
	scanf("%s", str);
	if (strlen(str) > 18)
	{
		printf("\t\t\tUsername is not available.\n\n\t\t\t");
		system("pause");
		system("cls");
		signUp();
		return;
	}
	for (i = 0; i < userCount; i++) //检查重名
	{
		if (strcmp(user[i].id, str) == 0)
		{
			printf("\t\t\tUsername is not available.\n\n\t\t\t");
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

	system("cls");
	printf("\n\t\t\tPlease select Administrator permission or not.\n\n\t\t\t");
	printf("\n\t\t\t(Y/N)\n\n\t\t\t");
	getchar();
	char ch;
	ch = getchar();
	user[i].role = ch;
	saveUser();
	printf("\t\t\tAccount application succeeded.\n\n\t\t\t");
	system("pause");
	system("cls");
	loginMenu();
	return;
}
void signIn()
{
	system("cls");
	int i = 0;
	int flag = 0;
	char str[50];
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
	getchar();
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
	if (user[i].role == 'y' || user[i].role == 'Y')
	{
		printf("\n\t\t\tWelcome Administrator\t\t\t");
		printf("\n\t\t\tLoading...\t\t\t");
		printf("\n\t\t\tLoading...\t\t\t");
		printf("\n\t\t\tSucceed...\n\t\t\t");
		system("pause");
		systemMenu1();
	}
	else
	{
		printf("\n\t\t\tWelcome %s\t\t\t", user[i].id);
		printf("\n\t\t\tLoading...\t\t\t");
		printf("\n\t\t\tLoading...\t\t\t");
		printf("\n\t\t\tSucceed...\n\t\t\t");
		system("pause");

		systemMenu2();
	}
}
void reSetPassport(void)
{
	system("cls");
	int i = 0;
	int flag = 0;
	char str[20];
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
	getchar();
	scanf("%s", str);
	while (strcmp(user[i].passport, str) != 0)
	{
		system("cls");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n\t\t\tYour passport is wrong please try it again");
		scanf("%s", str);
	}
	printf("\n\t\t\tPlease enter your new passport:");
	scanf("%s", str);
	strcpy(user[i].passport, str);
	printf("\n\t\t\tPlease enter your passport again:");
	scanf("%s", str);
	while (strcmp(user[i].passport, str) != 0)
	{
		printf("\t\t\tPlease try it again.\n\n\t\t\t");
		system("PAUSE");
		system("cls");
		printf("\n");
		scanf("%s", str);
	}
	saveUser();
	printf("\n\t\t\tLoading...\t\t\t");
	printf("\n\t\t\tLoading...\t\t\t");
	printf("\n\t\t\tSucceed...\n\t\t\t");
	system("pause");
	loginMenu();
}

void addStudentInfo()
{
	system("cls");
	int num;
	int i;
	char gender[5];
	char name[20];
	float chem;
	float biology;
	float physical;
	float totalScore;
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\t\t\t\t Please enter student num:");

	scanf("%d", &num);
	student[studentCount].num = num;
	getchar();

	printf("\n\t\t\t\t Please enter student name:");
	scanf("%s", name);
	strcpy(student[studentCount].name, name);
	getchar();

	printf("\n\t\t\t\t Please enter student gender:");
	scanf("%s", gender);
	strcpy(student[studentCount].gender, gender);
	getchar();

	printf("\n\t\t\t\t Please enter student chemisty score:");
	scanf("%f", &chem);
	student[studentCount].chem = chem;
	getchar();

	printf("\n\t\t\t\t Please enter student bilolgy score:");
	scanf("%f", &biology);
	student[studentCount].biology = biology;
	getchar();

	printf("\n\t\t\t\t Please enter student physical score:");
	scanf("%f", &physical);
	student[studentCount].physical = physical;
	getchar();
	totalScore = chem + biology + physical;
	student[studentCount].totalScore = totalScore;
	saveStudent();
	printf("\n\t\t\t\t");
	system("pause");
	systemMenu1();
	return;


}
void deleteStudentInfo()
{
	while (1)
	{
		system("cls");
		printStudentInfo();
		printf("\n\n\t\t\t\t                                       ");
		printf("\n\n\t\t\t\t                                       ");
		printf("\n\t\t\t\Please enter the student number you want to delete:1001");
		int studentNum = 0;
		scanf("%d", studentNum);
		int t = -1;
		for (int i = 0; i <= studentCount; i++) //遍历数组找到删除的学号
		{
			if (studentNum == student[i].num)
			{
				t = i;
				break;
			}
		}
		if (t == -1) //未找到学号，返回上一级菜单
		{
			printf("Error input please try it again.");
			systemMenu1();
		}
		printf("\n\t\t\t Student Number:%d",student[t].num);
		printf("\n\t\t\t Student Name:%s",student[t].name);
		printf("\n\t\t\t Deletion confirm(1/0)");
		scanf("%d", &t);
		
		if (t == 1) {
			printf("\n\t\t\tDelete success.\n\t\t\t");
			system("pause");
		}
		for (int i = t; i <= studentCount; i++)
		{
			student[t] = student[t + 1];
		}
		saveStudent();
		break;
	}
	systemMenu1();
	return;
}
void updateStudentInfo()
{
	int t = -1;
	while (1)
	{
		system("cle");
		system("cls");
		printStudentInfo();
		printf("\n\n\t\t\t\t                                       ");
		printf("\n\n\t\t\t\t                                       ");
		printf("\n\t\t\t\Please enter the student number you want to update:");
		int studentNum;
		scanf("%d", &studentNum);
		for (int i = 0; i < studentCount; i++)
		{
			if (studentNum == student[i].num)
			{
				t = i;
				break;
			}
		}
		if (t == -1) //未找到学号，返回上一级菜单
		{
			printf("Error input please try it again.");
			systemMenu1();
		}
		printf("\n\t\tStudentNum  StudentName  StudentGender Chemisty Bilolgy Physical totalScore");
		printf("\n\n\t\t%10d%10s%10s        %8.2f %8.2f %8.2f %8.2f",
			student[t].num, student[t].name, student[t].gender, student[t].chem,
			student[t].biology, student[t].physical, student[t].totalScore);
		int num;
		char gender[5];
		char name[20];
		float chem;
		float biology;
		float physical;
		float totalScore;
		printf("\n\t\t\t\t Please enter new student num:");

		scanf("%d", &num);
		student[t].num = num;
		getchar();
		printf("\n\t\t\t\t Please enter new student name:");
		scanf("%s", name);
		strcpy(student[t].name, name);
		getchar();

		printf("\n\t\t\t\t Please enter student gender:");
		scanf("%s", gender);
		strcpy(student[t].gender, gender);
		getchar();

		printf("\n\t\t\t\t Please enter student chemisty score:");
		scanf("%f", &chem);
		student[t].chem = chem;
		getchar();

		printf("\n\t\t\t\t Please enter student bilolgy score:");
		scanf("%f", &biology);
		student[t].biology = biology;
		getchar();

		printf("\n\t\t\t\t Please enter student physical score:");
		scanf("%f", &physical);
		student[t].physical = physical;
		getchar();
		totalScore = chem + biology + physical;
		student[t].totalScore = totalScore;
		saveStudent();
		printf("  \n\t\t");
		system("pause");
		break;
	}
	systemMenu1();
	return;
}

void printAccount()
{
	system("cls");
	for (int i = 0; i < userCount; i++)
	{
		printf("\n\t\t\t");
		printf("\n\t\t\tAccount:%s,Passport:%s,Administrator or not（Y/N）%c\t\t\t",
			user[i].id, user[i].passport, user[i].role);
		printf("\n");
	}
}
void printStudentInfo() //打印所有学生
{
	system("cls");
	printf("\n\t\t\t                                       ");
	printf("\n\t\tStudentNum  StudentName  StudentGender Chemisty Bilolgy Physical totalScore");
	for (int i = 0; i <= studentCount; i++)
	{
		printf("\n\n\t\t%10d%10s%10s        %8.2f %8.2f %8.2f %8.2f",
			student[i].num, student[i].name, student[i].gender, student[i].chem,
			student[i].biology, student[i].physical, student[i].totalScore);
	}
}

void loginMenu()	//登录界面
{
	system("cls");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\t\t\t\t                Student management system");
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
			reSetPassport(); break;
		default:
			system("cls");
			printf(" \n\n\n\n\n\t\t\t\t\t");
			system("pause");
			loginMenu();
			break;
		}
	}
}
void systemMenu1()    //管理员菜单
{
	system("cls");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\t\t\t\t               Student management system  ");
	printf("\n");
	printf("\n\t\t\t              1、   Add Student information");
	printf("\n\t\t\t              2、   Delete student information      ");
	printf("\n\t\t\t              3、   Update student information ");
	printf("\n\t\t\t              4、   Search student information ");
	printf("\n\t\t\t              5、   Add user account ");
	printf("\n\t\t\t              6、   Print user information ");
	printf("\n\t\t\t              7、   Exit ");
	printf("\n\t\t\t                        please enter your choice：");
	int i;
	while (1)
	{
		scanf("%d", &i);

		switch (i)
		{
		case 1:
			addStudentInfo(); break;
		case 2:
			deleteStudentInfo(); break;
		case 3:
			updateStudentInfo(); break;
		case 4:
			selectMenu1; break;
		case 5:
			signUp(); break;
		case 6:
			printAccount(); break;
		case 7:
			system("cls");
			loginMenu();
		default:
			system("cls");
			printf(" \n\n\n\n\n\t\t\t\t\t");
			system("pause");
			systemMenu1();
			break;
		}
	}
}
void selectMenu1()
{
	system("cls");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\t\t\t\t                  Search Menu");
	printf("\n");
	printf("\n\t\t\t              1、   Search by number");
	printf("\n\t\t\t              2、   Search by name      ");
	printf("\n\t\t\t              3、   Exit ");
	printf("\n\t\t\t                        please enter your choice：");
	int i;
	while (1)
	{
		scanf("%d", &i);

		switch (i)
		{
		case 1:
			searchByNum(); break;
		case 2:
			searchByName(); break;
		case 3:
			systemMenu1(); break;
		default:
			system("cls");
			printf(" \n\n\n\n\n\t\t\t\t\t");
			system("pause");
			selectMenu1();
			break;
		}
	}
}
void systemMenu2()    //学生菜单
{
	system("cls");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\t\t\t\t               Student management system");
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
			studentSearch(); break;
		case 2: 
			loginMenu();
			break;	
		default:
			system("cls");
			printf(" \n\n\n\n\n\t\t\t\t\t");
			system("pause");
			systemMenu2();
			break;
		}
	}
}
void studentSearch()
{
	int studentNum;
	system("cls");
	printf(" \n\n\n\n\n\t\t\t\t\t");
	printf("Please enter your student number:");
	scanf("%d", &studentNum);
	int t = -1;
	for (int i = 0; i <= studentCount; i++)
	{
		if (studentNum == student[i].num)
		{
			system("cls");
			printf("\n\t\t\t                                       ");
			printf("\n\t\t\tSearch success");
			printf("\n\t\tStudentNum  StudentName  StudentGender Chemisty Bilolgy Physical totalScore");
			printf("\n\n\t\t%10d%10s%10s        %8.2f %8.2f %8.2f %8.2f",
				student[i].num, student[i].name, student[i].gender, student[i].chem,
				student[i].biology, student[i].physical, student[i].totalScore);
			t = 0;
		}
	}
	if (t == -1) //未找到学号，返回上一级菜单
	{
		printf("Error input please try it again.");
		systemMenu2();
	}
	else
	{
		printf(" \n\t\t\t");
		system("pause");
		systemMenu2();
	}
}
void searchByNum()
{
	while (1)
	{
		int studentNum;
		system("cls");
		printf(" \n\n\n\n\n\t\t\t\t\t");
		printf("Please enter your student number:");
		scanf("%d", &studentNum);
		int t = -1;
		for (int i = 0; i <= studentCount; i++)
		{
			if (studentNum == student[i].num)
			{
				system("cls");
				printf("\n\t\t\t                                       ");
				printf("\n\t\t\tSearch success");
				printf("\n\t\tStudentNum  StudentName  StudentGender Chemisty Bilolgy Physical totalScore");
				printf("\n\n\t\t%10d%10s%10s        %8.2f %8.2f %8.2f %8.2f",
					student[i].num, student[i].name, student[i].gender, student[i].chem,
					student[i].biology, student[i].physical, student[i].totalScore);
				t = 0;
			}
		}
		if (t == -1) //未找到，返回上一级菜单
		{
			printf("Error input please try it again.");
			continue;
		}
		else
		{
			printf("\n\t\t\t");
			system("pause");
			selectMenu1();
		}
	}
}
void searchByName()
{
	while (1)
	{
		char studentName[20];
		system("cls");
		printf(" \n\n\n\n\n\t\t\t\t\t");
		printf("Please enter your student number:");
		scanf("%s", studentName);
		int t = -1;
		for (int i = 0; i <= studentCount; i++)
		{
			if (strcmp(studentName,student[i].name))
			{
				system("cls");
				printf("\n\t\t\t                                       ");
				printf("\n\t\t\tSearch success");
				printf("\n\t\tStudentNum  StudentName  StudentGender Chemisty Bilolgy Physical totalScore");
				printf("\n\n\t\t%10d%10s%10s        %8.2f %8.2f %8.2f %8.2f",
					student[i].num, student[i].name, student[i].gender, student[i].chem,
					student[i].biology, student[i].physical, student[i].totalScore);
				t = 0;
			}
		}
		if (t == -1) //未找到，返回上一级菜单
		{
			printf("Error input please try it again.");
			continue;
		}
		else
		{
			printf("\n\t\t\t");
			system("pause");
			selectMenu1();
		}
	}
}