#include"my_library.h"
//ͷ�巨
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
//��ӡ����
void lise_print(pStudent_t p_head)
{
	while (1)
	{
		printf("%3d", p_head->num);
		p_head->pNext;
	}
}
//β�巨
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
//�������
void list_in_sert(pStudent_t* pp_head, Student_t** pp_tail, int val)
{
	pStudent_t p_new = (pStudent_t)calloc(1, sizeof(Student_t));
	pStudent_t pCur = *pp_head; //����һ��
	pStudent_t pPre = *pp_head;
	p_new->num = val;
	if (NULL == *pp_head)
	{
		*pp_head = p_new;
		*pp_tail = p_new;
	}
	else if (val < pCur->num) //С�� ͷ�ڵ� ��ͷ�巨
	{
		p_new->pNext = *pp_head;
		*pp_head = p_new;
	}
	else //����ͷ�ڵ� ��������� ���Ƿ��ܲ��������м�
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
	if (NULL == pCur)  //������֮���޷����� ���뵽β��
	{
		(*pp_tail)->pNext = p_new;
		*pp_tail = p_new;
	}
}