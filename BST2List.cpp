#include <iostream>

struct BinaryTreeNode
{
  int val;
  BinaryTreeNode* pLeft;
  BinaryTreeNode* pRight;
};

typedef BinaryTreeNode DoubleLinkedList;


DoubleLinkedList* bst2list(BinaryTreeNode* root)
{
  if (root == NULL) return NULL;
  DoubleLinkedList* head = root;
  if (root->pLeft)
  {
    DoubleLinkedList* lhead =  bst2list(root->pLeft);
    head = lhead;
    // go to list tail
    while(lhead->pRight)
    {
      lhead = lhead->pRight;
    }
    lhead->pRight = root;
    root->pLeft = lhead;
  }
  if (root->pRight)
  {
    DoubleLinkedList* rhead = bst2list(root->pRight);
    root->pRight = rhead;
    rhead->pLeft = root;
  }
  return head;

}
