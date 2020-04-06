#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
using namespace std;
struct account //账户信息
{
	char id[20];
	char passport[20];
	char role;
};

typedef struct list  //学生信息
{
	int num;
	char gender[5];
	char name[20];
	float chem;
	float biology;
	float physical;
	float totalScore;
}Student_t;

void loadUser(void);	        //读取账号信息
void saveUser(void);	        //写入账号信息
void loadStudent(void);	        //读取学生信息
void saveStudent(void);			//写入学生信息

void signUp(void);			    //注册用户
void signIn(void);		        //用户登录
void reSetPassport(void);	    //修改密码

void addStudentInfo(void);	    //添加学生信息
void deleteStudentInfo(void);   //删除学生信息
void updateStudentInfo(void);   //更新学生信息

void printAccount(void);        //打印所有账户信息
void printStudentInfo(void);	//打印所有学生信息

void loginMenu(void);		    //登录界面
void systemMenu1(void);         //管理员菜单
void searchByNum(void);			//按学号查找
void searchByName(void);		//按名字查找
void selectMenu1(void);			//管理员选择菜单
void systemMenu2(void);         //学生菜单
void studentSearch(void);		//学生查找
