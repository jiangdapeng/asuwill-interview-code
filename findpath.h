#ifndef FIND_PATH_H
#define FIND_PATH_H


/*
4.在二元树中找出和为某一值的所有路径
题目：输入一个整数和一棵二元树。
从树的根结点开始往下访问一直到叶结点所经过的所有结点形成一条路径。
打印出和与输入整数相等的所有路径。
例如 输入整数22和如下二元树
  10   
  / \   
  5 12   
  / \   
  4 7
则打印出两条路径：10, 12和10, 5, 7。
*/

#include"bt2list.h"
#include <vector>

void printpath(const std::vector<BSTreeNode*>& path)
{
	using namespace std;
	for(int i=0;i<path.size();++i)
		cout<<path[i]->m_iValue<<" ";
	cout<<endl;
}

void visit(BSTreeNode* node,int sum,int value,std::vector<BSTreeNode*>& path)
{
	sum+=node->m_iValue;
	path.push_back(node);
	if(node->m_pLeft!=NULL)
	{
		visit(node->m_pLeft,sum,value,path);
	}
	if(node->m_pRight!=NULL)
	{
		visit(node->m_pRight,sum,value,path);
	}
	if(node->m_pLeft ==NULL && node->m_pRight ==NULL)
	{
		//leaf node
		if(sum == value)
			printpath(path);
	}
	path.pop_back();
}

void findpath(BSTreeNode* root,int value)
{
	std::vector<BSTreeNode*> path;
	if(root != NULL)
		visit(root,0,value,path);
}

#endif