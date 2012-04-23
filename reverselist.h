#ifndef REVERSE_LIST_H
#define REVERSE_LIST_H

#include "list.h"

//reverse linked list 
//no recursive style
List* reverse_list(List* head)
{
	if(head == NULL)
		return NULL;
	List *next = NULL;
	List *cur=head->m_pNext;
	head->m_pNext = NULL;
	while(cur)
	{
		next = cur->m_pNext;
		cur->m_pNext = head;
		head = cur;
		cur = next;
	}
	return head;
}

//reverse linked list
//recursive style
List* reverse_list_r(List* head)
{
	if(head->m_pNext == NULL)
		return head;
	List *tmp1 = head;
	head = reverse_list_r(head->m_pNext);
	List *tmp2 = head;
	while(tmp2 && tmp2->m_pNext)
		tmp2 = tmp2->m_pNext;
	tmp2->m_pNext = tmp1;
	tmp1->m_pNext = NULL;
	return head;
}

#endif