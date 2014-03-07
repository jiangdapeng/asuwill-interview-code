#include <iostream>
#include <vector>

struct BinaryTreeNode
{
  int val;
  BinaryTreeNode* pLeft;
  BinaryTreeNode* pRight;
};

vector<vector<int> > paths;
vector<int> curpath;

// assume node's value are greater than or equal to 0
void find_path(BinaryTreeNode* root, int n)
{
  if (root == NULL) return;
  if (root->val  <= n)
  {
    curpath.push_back(root->val);
    n -= root->val;
    if (n == 0 && root->pLeft == NULL && root->pRight == NULL)
    {
      // find a path 
      paths.push_back(curpath);
    }
    else
    {
      if (root->pLeft)
      {
        find_path(root->pLeft, n);
      }
      if (root->pRight)
      {
        find_path(root->pRight, n);
      }
    }
    curpath.pop_back();
  }
}

int main()
{
  return 0;
}
