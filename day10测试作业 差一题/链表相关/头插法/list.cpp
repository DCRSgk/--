#include"my_library.h"
//头插法
void list_head_in_sert(pStudent_t* pp_head, Student_t** pp_tail, int val)
{
	pStudent_t p_new = (pStudent_t)calloc(1, sizeof(Student_t));
	p_new->num = val;
	if (*pp_head == NULL)
	{
		*pp_head = p_new;
		*pp_tail = p_new;
	}
	else 
	{
		p_new->pNext = *pp_head;


		*pp_head = p_new;
	}

}	
//打印链表
void lise_print(pStudent_t p_head)
{
	while (1)
	{
		printf("%3d", p_head->num);
		p_head->pNext;
	}
}
//尾插法
void list_tail_in_sert(pStudent_t* pp_head, Student_t** pp_tail, int val)
{
	pStudent_t p_new = (pStudent_t)calloc(1, sizeof(Student_t));
	p_new->num = val;
	if(NULL==*pp_tail)
	{
		*pp_head = p_new;
		*pp_tail = p_new;
	}
	else
	{
		(*pp_tail)->pNext = p_new;
		*pp_tail = p_new;
	}
}
//有序插入
void list_in_sert(pStudent_t* pp_head, Student_t** pp_tail, int val)
{
	pStudent_t p_new = (pStudent_t)calloc(1, sizeof(Student_t));
	pStudent_t pCur = *pp_head; //复制一份
	pStudent_t pPre = *pp_head;
	p_new->num = val;
	if (NULL == *pp_head)
	{
		*pp_head = p_new;
		*pp_tail = p_new;
	}
	else if (val < pCur->num) //小于 头节点 用头插法
	{
		p_new->pNext = *pp_head;
		*pp_head = p_new;
	}
	else //大于头节点 则遍历链表 看是否能插入链表中间
	{
		while (pCur)
		{
			if (pCur->num > val) //
			{
				pPre->pNext = p_new;
				p_new->pNext = pCur;
				break;
			}
			pPre = pCur;
			pCur = pCur->pNext;
		}
		
	}
	if (NULL == pCur)  //若遍历之后无法插入 插入到尾部
	{
		(*pp_tail)->pNext = p_new;
		*pp_tail = p_new;
	}
}