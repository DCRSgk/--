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
struct account //�˻���Ϣ
{
	char id[20];
	char passport[20];
};

typedef struct list  //ѧ����Ϣ
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

void saveUser(void);  //д���˺���Ϣ
void loadUser(void);  //��ȡ�˺���Ϣ
void saveStudent(void);//д��ѧ����Ϣ
void loadStudent(void);//��ȡѧ����Ϣ

void loginMenu(void);	//��¼����
void signUp(void);   //ע���û�
void signIn(void);	 //��¼
void reSetPassport(void);   //�޸�����

void systemMenu1(void); //����Ա�˵�
void systemMenu2(void); //ѧ���˵�
void headInSert(pStudent_t* pphead, pStudent_t* pptail, char val);
void tailInSert(pStudent_t* pphead, pStudent_t* pptail, char val);
