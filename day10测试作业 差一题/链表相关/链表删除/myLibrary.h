#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef struct student {
	int num; //ѧ��
	char name[20];
	float cham;
	float biology;
	float phy;
	float score;//�ܳɼ�
	struct student* pNext; //����ָ��int
}Student_t, * pStudent_t;
void ListDelete(pStudent_t* pphead, student** ppTail, int deleteNum);;
void ListMdify(pStudent_t phead,int num,float score);