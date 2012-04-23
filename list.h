#ifndef LIST_H
#define LIST_H

#include <iostream>

struct List
{
	int   m_iValue;
	List* m_pNext;
};


List* buildList(bool circle=false)
{
	List* head = new List;
	head->m_pNext = NULL;
	head->m_iValue = 0;
	List* tmp = head;
	for(int i=1;i<5;++i)
	{
		tmp->m_pNext = new List;
		tmp = tmp->m_pNext;
		tmp->m_iValue = i;
		tmp->m_pNext = NULL;
	}
	if(circle)
		tmp->m_pNext = head->m_pNext;
	return head;
}

//free Acyclic list
void freeList(List* head)
{
	List *tmp = head;
	while(tmp)
	{
		head = tmp->m_pNext;
		delete tmp;
		tmp = head;
	}
}

void display(List *head)
{
	using namespace std;
	List *tmp = head;
	while(tmp)
	{
		cout<<tmp->m_iValue<<" ";
		tmp = tmp->m_pNext;
	}
	cout<<endl;
}

#endif