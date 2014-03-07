#include <iostream>
#include <map>

using std::map;

struct ComplexListNode
{
  int val;
  ComplexListNode* pNext;
  ComplexListNode* pSibling;
};

typedef map<ComplexListNode*, ComplexListNode*>::iterator IterType;

ComplexListNode* do_clone(ComplexListNode* pNode, map<ComplexListNode*, ComplexListNode*>& old2new)
{
  if (pNode == NULL) return NULL;
  IterType it = old2new.find(pNode);
  if (it != old2new.end())
  {
    return it->second;
  }
  else 
  {
    ComplexListNode* pNew = new ComplexListNode();
    pNew->val = pNode->val;
    old2new[pNode] = pNew;
    pNew->pNext = do_clone(pNode->pNext, old2new);
    pNew->pSibling = do_clone(pNode->pSibling, old2new);
    return pNew;
  }
}

ComplexListNode* deep_clone(ComplexListNode* pHead)
{
  if (pHead == NULL) return NULL;
  map<ComplexListNode*, ComplexListNode*> old2new;
  return do_clone(pHead, old2new);
}
