
/**
* @file bt2list.cpp
* @brief transform binary search tree to double linked queue
* @author asuwill.jdp@gmail.com
* @date 2012-04-21
*/

#ifndef BST2LIST_H
#define BST2LIST_H

#include "bst.h"
#include <iostream>

//internal method, do not call this method directly
BSTreeNode* bt2list(BSTreeNode* root,bool left)
{
	//root should not be NULL
	if(root->m_pLeft != NULL)
	{
		root->m_pLeft = bt2list(root->m_pLeft,true);
		root->m_pLeft->m_pRight = root;
	}
	if(root->m_pRight !=NULL)
	{
		root->m_pRight = bt2list(root->m_pRight,false);
		root->m_pRight->m_pLeft = root;
	}
	if(left)
	{
		//return the right most node
		BSTreeNode* tmp = root;
		while(tmp->m_pRight)
			tmp = tmp->m_pRight;
		return tmp;
	}
	else
	{
		//return the left most node
		BSTreeNode* tmp = root;
		while(tmp->m_pLeft)
			tmp = tmp->m_pLeft;
		return tmp;
	}
}

// public interface
BSTreeNode* bt2list(BSTreeNode* root)
{
	if(root == NULL)
		return NULL;
	return bt2list(root,false);
}

//print double linked list
//check if the transfomation is correct
void display(BSTreeNode* list)
{
	std::cout<<"list:"<<std::endl;
	BSTreeNode* tmp = list;
	while(tmp)
	{
		std::cout<<tmp->m_iValue<<std::endl;
		tmp=tmp->m_pRight;
	}
}

//remember to free the allocated memory
void freeList(BSTreeNode* list)
{
	BSTreeNode* tmp = list;
	while(tmp)
	{
		list = tmp->m_pRight;
		delete tmp;
		tmp = list;
	}
}

#endif

