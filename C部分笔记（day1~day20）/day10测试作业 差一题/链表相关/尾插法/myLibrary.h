#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef struct student {
	int num; //学号
	char name[20]; 
	float cham;
	float biology;
	float phy;
	float score;//总成绩
	struct student* pNext; //链表指针
}Student_t, * pStudent_t;
void ListTailInSert(pStudent_t* pp_head, Student_t** pp_tail, int val); //尾插法
void ListHeadInSert(pStudent_t * pp_head, Student_t * *pp_tail, int val); 
void numSert(pStudent_t* ppHead, Student_t** ppTail, Student_t val);//
void ListPrint(pStudent_t pHead);
