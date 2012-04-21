
/**
* @file bt2list.cpp
* @brief transform binary search tree to double linked queue
* @author asuwill.jdp@gmail.com
* @date 2012-04-21
*/
#include <iostream>
using namespace std;

// if you want to reuse this code  for more
// value type, change this code to template style
struct BSTreeNode
{
	int m_iValue;   //node value
	BSTreeNode* m_pLeft;
	BSTreeNode* m_pRight;
};

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


// for construction of binary tree
BSTreeNode* insert(BSTreeNode* root,int value)
{
	if(root == NULL)
	{
		root = new BSTreeNode;
		root->m_pLeft = root->m_pRight = NULL;
		root->m_iValue = value;
	}
	else if(root->m_iValue>value)
	{
		root->m_pLeft = insert(root->m_pLeft,value);
	}
	else if(root->m_iValue < value)
		root->m_pRight = insert(root->m_pRight,value);
	return root;
}

//bulid a binary search tree
//for test
BSTreeNode* buildTree(int n)
{
	BSTreeNode* root = NULL;
	for(int i=0;i<n;++i)
	{
		int value;
		cin>>value;
		root = insert(root,value);
	}
	return root;
}

//to check if the tree is constructed in the right way
void visitTree(BSTreeNode* root)
{
	if(root)
	{
		visitTree(root->m_pLeft);
		cout<<root->m_iValue<<endl;
		visitTree(root->m_pRight);
	}
}

//print double linked list
//check if the transfomation is correct
void display(BSTreeNode* list)
{
	cout<<"list:"<<endl;
	BSTreeNode* tmp = list;
	while(tmp)
	{
		cout<<tmp->m_iValue<<endl;
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

int main()
{
	int n;
	cin>>n;
	BSTreeNode* root = buildTree(n);
	//visitTree(root);
	BSTreeNode* list = bt2list(root);
	display(list);
	freeList(list);
}

