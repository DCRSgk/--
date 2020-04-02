#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<windows.h>
using namespace std;
static int userCount = 0;
typedef struct Account //账户信息
{
	char id[20];
	char passport[20];
	bool permission;
}user;

typedef struct list  //学生信息
{
	int num;
	char name[20];
	char sex;
	float chem;
	float biblogy;
	float physical;
	float score;
	struct list* pNext;
}Student_t, * pStudent_t;

void addUser();
void signUp(void);  //添加用户
bool signIn(void);	 //登录
void reSetPassport(void);   //修改密码
void systemMenu(void);

void headInSert(pStudent_t* pphead, pStudent_t* pptail, char val);
void tailInSert(pStudent_t* pphead, pStudent_t* pptail, char val);