#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
using namespace std;
struct account //�˻���Ϣ
{
	char id[20];
	char passport[20];
	char role;
};

typedef struct list  //ѧ����Ϣ
{
	int num;
	char gender[5];
	char name[20];
	float chem;
	float biology;
	float physical;
	float totalScore;
}Student_t;

void loadUser(void);	        //��ȡ�˺���Ϣ
void saveUser(void);	        //д���˺���Ϣ
void loadStudent(void);	        //��ȡѧ����Ϣ
void saveStudent(void);			//д��ѧ����Ϣ

void signUp(void);			    //ע���û�
void signIn(void);		        //�û���¼
void reSetPassport(void);	    //�޸�����

void addStudentInfo(void);	    //���ѧ����Ϣ
void deleteStudentInfo(void);   //ɾ��ѧ����Ϣ
void updateStudentInfo(void);   //����ѧ����Ϣ

void printAccount(void);        //��ӡ�����˻���Ϣ
void printStudentInfo(void);	//��ӡ����ѧ����Ϣ

void loginMenu(void);		    //��¼����
void systemMenu1(void);         //����Ա�˵�
void searchByNum(void);			//��ѧ�Ų���
void searchByName(void);		//�����ֲ���
void selectMenu1(void);			//����Աѡ��˵�
void systemMenu2(void);         //ѧ���˵�
void studentSearch(void);		//ѧ������
