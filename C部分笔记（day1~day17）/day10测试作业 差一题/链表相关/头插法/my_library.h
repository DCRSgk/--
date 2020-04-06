#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef struct student {
	int num;
	struct student* pNext;
}Student_t,*pStudent_t;
void list_head_in_sert(pStudent_t* pp_head, Student_t** pp_tail, int val);
void list_tail_in_sert(pStudent_t* pp_head, Student_t** pp_tail, int val);
void list_in_sert(pStudent_t* pp_head, Student_t** pp_tail, int val);
void list_head_in_sert(pStudent_t* pp_head, Student_t** pp_tail, int val);