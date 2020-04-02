#include"myLibrary.h"
int main()
{
	int i;
	user Acco[1024];
	FILE* fp1;//学生信息
	FILE* fp2;//学生账户
	FILE* fp3;//其他
	fp1 = fopen("stu_info.txt", "r+");
	if (NULL == fp1)
	{
		perror("fopen");
		goto error;
	}
	fp2 = fopen("stu_account.txt", "r+");
	if (NULL == fp2)
	{
		perror("fopen");
		goto error;
	}
	fp3 = fopen("config.txt", "r+");
	if (NULL == fp3)
	{
		perror("fopen");
		goto error;
	}
	
	systemMenu();



error:
	system("pause");
}
