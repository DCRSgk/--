#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef struct List {
	int num;
	struct List* pNext;
}Student_t, * pStudent_t;
void listHeadInSert(pStudent_t* pp_head, pStudent_t* pp_tail, int val);
void listTailInSert(pStudent_t* pp_head, pStudent_t* pp_tail, int val);
void listInSert(pStudent_t* pp_head, pStudent_t* pp_tail, int val);
void listHeadInSert(pStudent_t* pp_head, pStudent_t* pp_tail, int val);