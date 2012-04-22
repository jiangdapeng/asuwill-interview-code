#ifndef LIST_INTERSECT_H
#define LIST_INTERSECT_H
/*
题目描述：
微软亚院之编程判断俩个链表是否相交
给出俩个单向链表的头指针，比如h1，h2，判断这俩个链表是否相交。
为了简化问题，我们假设俩个链表均不带环。

问题扩展：
1.如果链表可能有环?
2.如果需要求出俩个链表相交的第一个节点?
*/

#include <set>

struct List
{
	int m_iValue;
	List* m_pNext;
};

// circle exists? 
/*
bool is_circle_exists(List* pHead,List*& ppStart)
{
	using namespace std;
	set<List*> visited;
	set<List*>::iterator it;
	List* tmp = pHead;
	while(tmp)
	{
		it = visited.find(tmp);
		if(it!=visited.end())
		{
			ppStart = *it;//record the circle start point
			return true;
		}
		visited.insert(tmp);
		tmp=tmp->m_pNext;
	}
	ppStart = NULL;
	return false;
}
*/
//在别人博客上看到一个更好的检测方法
//用不同的步伐遍历，如果有环，则两个遍历肯定相遇
bool is_circle_exists(List* pHead,List*& ppStart)
{
	if(pHead == NULL)
		return false;
	List* p1 = pHead;
	List* p2 = pHead->m_pNext;
	while(p2 && p2->m_pNext)
	{
		p1 = p1->m_pNext;
		p2 = p2->m_pNext->m_pNext;
		if(p1 == p2)
		{
			ppStart = p1;
			return true;
		}
	}
	ppStart = NULL;
	return false;
}


//list without circle
bool is_intersect_nc(List* head1,List* head2)
{
	List* tmp1;
	List* tmp2;
	tmp1 = head1;
	tmp2 = head2;
	while(tmp1 && tmp1->m_pNext)
		tmp1 = tmp1->m_pNext;
	while(tmp2 && tmp2->m_pNext)
		tmp2 = tmp2->m_pNext;
	return tmp1==tmp2?true:false;
}

//lists with or without circle 
bool is_intersect(List* head1,List* head2)
{
	List* cs1=NULL;
	List* cs2=NULL;
	bool c1 = is_circle_exists(head1,cs1);
	bool c2 = is_circle_exists(head2,cs2);
	if(c1 && c2)
	{
		//both have circle
		// check whether cs1 is in the circle start from cs2
		List* tmp = cs1->m_pNext;
		while(tmp && tmp!=cs1)
		{
			if(tmp == cs2)
				return true;
			tmp = tmp->m_pNext;
		}
		return tmp==cs2?true:false;
	}
	else if(!(c1||c2))
	{
		//neither has circle
		return is_intersect_nc(head1,head2);
	}
	else
		//one has,the other has no
		return false;
}

#endif