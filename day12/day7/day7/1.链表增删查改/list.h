#include <stdio.h>
#include <stdlib.h>


typedef struct student{
	int num;
	float score;
    struct student *pNext;
}Student_t,*pStudent_t;

void listHeadInsert(pStudent_t *,Student_t **,int );
void listTailInsert(pStudent_t *,Student_t **,int );
void listSortInsert(pStudent_t *,Student_t **,int );
void listDelete(pStudent_t *,pStudent_t*,int );
void listModify(pStudent_t,int,float);
void listPrint(pStudent_t);