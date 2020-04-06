#include"myLibrary.h"

account user[1024]; //数组存储
int userCount = 0;
//Student_t student[1024];  
//int studentCount = 0;

pStudent_t phead = NULL;

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
void loadStudent(pStudent_t* pphead)
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
	while (fscanf(fp, "%d %s %s %f %f %f %f", &num, name, gender, &chem, &biology, &physical, &totalScore) != EOF)
	{
		sortStudentInfor(pphead, num, name, gender, chem, biology, physical, totalScore);
	}
	fclose(fp);
}
void saveStudent(pStudent_t pSavehead)
{
	FILE* fp;
	fp = fopen("stuInfo.txt", "w");
	while (pSavehead)
	{
		fprintf(fp, "%d %s %s %5.2f %5.2f %5.2f %5.2f\n", pSavehead->num,
			pSavehead->name, pSavehead->gender,
			pSavehead->chem, pSavehead->biology,
			pSavehead->physical, pSavehead->totalScore);
		pSavehead = pSavehead->pNext;
	}
	fflush(fp);
	fclose(fp);
}
void sortStudentInfor(pStudent_t* pphead, int studentNum, char studentName[], char studentGender[],
	double chem, double biology, double physical, double totalScore)		//有序建立学生信息

{
	system("cls");
	pStudent_t pNew = (pStudent_t)calloc(1, sizeof(Student_t));
	pStudent_t pCur = *pphead;
	pStudent_t pPre = *pphead;


	strcmp(pNew->gender, studentGender);
	strcmp(pNew->name, studentName);
	pNew->num = studentNum;
	pNew->chem = chem;
	pNew->biology = biology;
	pNew->physical = physical;
	pNew->totalScore = totalScore;
	if (NULL == *pphead)	//如果链表为空
	{
		*pphead = pNew;
	}
	else if (studentNum > pNew->num) //若值比头节点小
	{							     //则用头插法
		pNew->pNext = pCur;
		*pphead = pNew;
	}
	else                             //若比头节点大，则需判断
	{
		while (pCur)
		{
			if (pCur->num > studentNum)
			{
				pPre->pNext = pNew;
				pNew->pNext = pCur;
				break;
			}
			pPre = pCur;
			pCur = pCur->pNext;
		}
		if (NULL == pCur)  //若遍历之后无法插入 插入到尾部
		{
			pPre->pNext = pNew;
		}
	}
}

void loginMenu()	//登录界面
{
	system("cls");
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
			reSetPassport(); break;
		default:
			system("cls");
			loginMenu();
		}
	}
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
void printAccount()
{
	system("cls");
	for (int i = 0; i <= userCount; i++)
	{
		printf("\n\t\t\t");
		printf("\n\t\t\tAccount:%s,Passport:%s,Administrator or not（Y/N）%c\t\t\t",
			user[i].id, user[i].passport, user[i].role);
		printf("\n");
	}
}




void systemMenu1()    //管理员菜单
{
	system("cls");
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
			addStudentInfo(); break;
		case 2:
			//deleteStudentInfo; break;
		case 3:
			//
		case 4:
		case 5:
			signUp(); break;
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
	system("cls");
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

void printStudentInfo(pStudent_t phead) //打印所有学生
{
	system("cls");
	printf("\n\t\t\t                                       ");
	printf("\n\t\tStudentNumber   StudentName   StudentGender    Chemisty    Bilolgy    Physical    totaltotalScore");
	while (phead)
	{
		printf("\n\n\t\t    %d         %s           %s          %5.2f     %5.2f        %5.2f     %5.2f",
			phead->num, phead->name, phead->gender, phead->chem, phead->biology,
			phead->physical, phead->totalScore);
		phead = phead->pNext;
	}
}

void addStudentInfo(pStudent_t pAddhead)
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
	pStudent_t tmp = pAddhead;
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\t\t\t\t Please enter student num:");
	scanf("%d", &num);
	getchar();
	printf("\n\t\t\t\t Please enter student name:");
	scanf("%s", name);
	getchar();
	printf("\n\t\t\t\t Please enter student gender:");
	scanf("%s", gender);
	printf("\n\t\t\t\t Please enter student chemisty score:");
	scanf("%f", &chem);
	printf("\n\t\t\t\t Please enter student bilolgy score:");
	scanf("%f", &biology);
	printf("\n\t\t\t\t Please enter student physical score:");
	scanf("%f", &physical);
	printf("\n\t\t\t\t");
	totalScore = chem + biology + physical;
	/*pStudent_t pNew = (pStudent_t)calloc(1, sizeof(Student_t));
	pNew->num = num;
	pNew->chem = chem;
	pNew->biology = biology;
	pNew->physical = physical;
	pNew->totalScore = totalScore;
	strcpy(pNew->name, name);
	strcpy(pNew->gender, gender);*/
	sortStudentInfor(&tmp, num, name, gender,
		chem, biology, physical, totalScore);		//有序建立学生信息
	saveStudent(tmp);
}

void deleteStudentInfo(pStudent_t *pphead )
{
	system("cls");
	printStudentInfo(phead);
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\n\t\t\t\t                                       ");
	printf("\n\t\t\t\Please enter the number you want to delete:");
	int studentNum=0;
	scanf("%d", studentNum);
	
	pStudent_t pCur = *pphead;
	pStudent_t pTmp = *pphead;
	pStudent_t pPre;
	pPre = pCur;
	if (pCur)
	{
		if (pCur->num == studentNum)
		{
			*pphead = pCur->pNext;
			free(pCur);
			pCur = NULL;
			saveStudent(pTmp);
			return;
		}
	}
	else
	{
		while (pCur)
		{
			if (pCur->num == studentNum)
			{
				pPre->pNext = pCur->pNext;
				free(pCur);
				free(pCur);
				pCur = NULL;
				saveStudent(pTmp);
				return;
			}

			pPre = pCur;
			pCur = pCur->pNext;
		}
		printf("Error input please try it again.");
		systemMenu1();
	}
}

