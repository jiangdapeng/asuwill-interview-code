#ifndef LONGEST_PATH_H
#define LONGEST_PATH_H


/*
第11题
求二叉树中节点的最大距离...
如果我们把二叉树看成一个图，
父子节点之间的连线看成是双向的，
我们姑且定义"距离"为两节点之间边的个数。
写一个程序，
求一棵二叉树中相距最远的两个节点之间的距离
*/

#include "bst.h"  //测试的时候利用二叉搜索树来进行

struct Result
{
	int leftOrRight;//max(left,right)
	int leftAndRight;//max(left+right)
};

// 返回以root为根的二叉树中存在的最长路径值leftAndRight，
// 以及从root到叶子节点的最长路径leftOrRight
// 需要返回两个值，是因为上层需要中间节点的最长路径信息才能判断最后的最长路径
// 以root为根节点的二叉树中最长的路径存在有两种可能情况：
// 1、该路径经过root节点，这时，
//    路径长度=root到左子树叶子节点最远距离+root到右子树叶子节点的最远距离
// 2、不经过root节点，最长路径在左子树或者右子树中
// 因此整个递归过程需要向上层传递两个值
Result do_longest_path(BSTreeNode* root)
{
	Result result;
	if(root == NULL)
	{
		result.leftAndRight = 0;
		result.leftOrRight = -1;
		return result;
	}

	Result left;
	Result right;
	left = do_longest_path(root->m_pLeft);
	right = do_longest_path(root->m_pRight);

	result.leftOrRight = 1+max(left.leftOrRight,right.leftOrRight);
	result.leftAndRight = max(left.leftAndRight,right.leftAndRight);//先选出左右子树中的最长路径
	result.leftAndRight = max(2+left.leftOrRight+right.leftOrRight,result.leftAndRight);//再选择经过root节点的最长路径与不经过root节点的路径中长的那个
	return result;
}

// longest path from node to node
int longest_path(BSTreeNode * root)
{
	if(root == NULL)
		return 0;
	Result result= do_longest_path(root);
	return result.leftAndRight;
}

#endif