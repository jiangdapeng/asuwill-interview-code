/***************************************************************************
 * File:MinStack.h
 * Author:asuwill(asuwill.jdp@gmail.com)
 *
 * A LIFO stack class that supports O(1) push, pop, and find-min.  Here, the
 * find-min operation returns (but does not remove) the minimum value in the
 * stack.  This sort of stack is often used as a subroutine in other problems.
 * It can be used to construct a queue with equivalent properties by
 * using one of the many stack-to-queue constructions, for example.
 *
 * the basic idea here is: use extra space to store index to min value
 */

#ifndef MIN_STACK_H
#define MIN_STACK_H

#include<vector>     // use as stack
#include<functional> // std::less


template<typename T,
	typename Comparator = std::less<T> >
class MinStack
{
public:
	explicit MinStack(Comparator=Comparator());

	void push(const T& v);

	void pop();

	const T& top() const;

	const T& min() const;

	bool empty() const;

	size_t size() const;
private:
	std::vector<T> m_vStack;  //store value
	std::vector<int> m_iStack;//store index to min
	Comparator m_comp;
	
};

template<typename T,typename Comparator>
MinStack<T,Comparator>::MinStack(Comparator c)
	:m_vStack(),m_iStack(),m_comp(c)
{
}

template<typename T,typename Comparator>
bool MinStack<T,Comparator>::empty()const
{
	return m_vStack.empty();
}

template<typename T,typename Comparator>
size_t MinStack<T,Comparator>::size()const
{
	return m_vStack.size();
}

template<typename T,typename Comparator>
void MinStack<T,Comparator>::pop()
{
	m_vStack.pop_back();
	m_iStack.pop_back();
}

template<typename T,typename Comparator>
const T& MinStack<T,Comparator>::top() const
{
	return m_vStack.back();
}

template<typename T,typename Comparator>
const T& MinStack<T,Comparator>::min() const
{
	return m_vStack[m_iStack.back()];
}

template<typename T,typename Comparator>
void MinStack<T,Comparator>::push(const T& v)
{
	if(empty())
	{
		m_vStack.push_back(v);
		m_iStack.push_back(0);
	}
	else
	{
		size_t min_index = m_iStack.back();
		if(m_comp(v,min()))
			min_index = m_vStack.size();
		m_vStack.push_back(v);
		m_iStack.push_back(min_index);
	}
}

#endif
