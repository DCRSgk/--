#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
using namespace std;
struct account //账户信息
{
	char id[20];
	char passport[20];
};

typedef struct list  //学生信息
{
	char name[20];
	char sex[5];
	int num;
	float chem;
	float biblogy;
	float physical;
	float score;
	struct list* pNext;
}Student_t, * pStudent_t;

void saveUser(void);  //写入账号信息
void loadUser(void);  //读取账号信息
void saveStudent(void);//写入学生信息
void loadStudent(void);//读取学生信息

void loginMenu(void);	//登录界面
void signUp(void);   //注册用户
void signIn(void);	 //登录
void reSetPassport(void);   //修改密码

void systemMenu1(void); //管理员菜单
void systemMenu2(void); //学生菜单
void headInSert(pStudent_t* pphead, pStudent_t* pptail, char val);
void tailInSert(pStudent_t* pphead, pStudent_t* pptail, char val);
