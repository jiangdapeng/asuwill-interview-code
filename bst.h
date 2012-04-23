#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

// if you want to reuse this code  for more
// value type, change this code to template style
struct BSTreeNode
{
	int m_iValue;   //node value
	BSTreeNode* m_pLeft;
	BSTreeNode* m_pRight;
};


// for construction of binary tree
BSTreeNode* insert(BSTreeNode* root,const int value)
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

BSTreeNode* BSTMax(BSTreeNode* root)
{
	BSTreeNode* tmp = root;
	while(tmp && tmp->m_pRight)
		tmp = tmp->m_pRight;
	return tmp;
}

BSTreeNode* BSTMin(BSTreeNode* root)
{
	BSTreeNode* tmp = root;
	while(tmp && tmp->m_pLeft)
		tmp = tmp->m_pLeft;
	return tmp;
}

BSTreeNode* remove(BSTreeNode* root,const int value)
{
	if(root->m_iValue > value)
		root->m_pLeft = remove(root->m_pLeft,value);
	else if(value > root->m_iValue)
		root->m_pRight = remove(root->m_pRight,value);
	else
	{
		if(root->m_pLeft == NULL && root->m_pRight==NULL)
		{
			delete root;
			return NULL;
		}
		if(root->m_pLeft)
		{
			BSTreeNode *pMax = BSTMax(root->m_pLeft);
			root->m_iValue = pMax->m_iValue;
			root->m_pLeft = remove(root->m_pLeft,pMax->m_iValue);
		}
		else if(root->m_pRight)
		{
			BSTreeNode *pMin = BSTMin(root->m_pRight);
			root->m_iValue = pMin->m_iValue;
			root->m_pRight = remove(root->m_pRight,pMin->m_iValue);
		}
	}
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
		std::cin>>value;
		root = insert(root,value);
	}
	return root;
}

//to check if the tree is constructed in the right way
//inorder
void visitTree(BSTreeNode* root)
{
	if(root)
	{
		visitTree(root->m_pLeft);
		std::cout<<root->m_iValue<<std::endl;
		visitTree(root->m_pRight);
	}
}

#endif