#ifndef BST_MIRROR_H
#define BST_MIRROR_H

#include "bst.h"

/*
第15题：
题目：输入一颗二元查找树，将该树转换为它的镜像，
即在转换后的二元查找树中，左子树的结点都大于右子树的结点。
用递归和循环两种方法完成树的镜像转换。   
例如输入：
  8
 / \
6 10
/\ /\
5 7 9 11
输出：
 8
/ \
10 6
/\ /\
11 9 7 5
定义二元查找树的结点为：
struct BSTreeNode // a node in the binary search tree (BST)
{
 int m_nValue; // value of node
 BSTreeNode *m_pLeft; // left child of node
 BSTreeNode *m_pRight; // right child of node
};
*/

#include <stack>

//recursive
BSTreeNode* mirror_r(BSTreeNode* root)
{
    if(root == NULL)
        return NULL;
    BSTreeNode* tmp = root->m_pLeft;
    root->m_pLeft = mirror_r(root->m_pRight);
    root->m_pRight = mirror_r(tmp);
    return root;
}

//none recursive
BSTreeNode* mirror(BSTreeNode* root)
{
    using namespace std;
    if(root == NULL)
        return NULL;
    stack<BSTreeNode*> sb;
    BSTreeNode* tmp = root;
    BSTreeNode* p = NULL;
    while(tmp!=NULL || !sb.empty())
    {
        if(tmp!=NULL)
        {
            sb.push(tmp);
            tmp = tmp->m_pLeft;
        }
        else
        {
            p = sb.top();
            sb.pop();
            tmp = p->m_pLeft;
            p->m_pLeft = p->m_pRight;
            p->m_pRight = tmp;
            tmp = p->m_pLeft;
        }
    }
    return root;
}

#endif

