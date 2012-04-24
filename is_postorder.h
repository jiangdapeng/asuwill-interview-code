#ifndef IS_POSTORDER_H
#define IS_POSTORDER_H

/*
判断整数序列是不是二元查找树的后序遍历结果
题目：输入一个整数数组，判断该数组是不是某二元查找树的后序遍历的结果。
如果是返回true，否则返回false。
例如输入5、7、6、9、11、10、8，由于这一整数序列是如下树的后序遍历结果：
  8
  / \
  6 10
  / \ / \
  5 7 9 11
因此返回true。
如果输入7、4、6、5，没有哪棵树的后序遍历的结果是这个序列，因此返回false
*/

//judge whether the number sequence is a result of 
//postorder visit of some binary search tree

bool is_postorder(int seq[],int n)
{
	int root = seq[n-1];//root is the last visited element
	int i,j;
	//left child elements are all less than root
	for(i=0;i<n-1;++i)
	{
		if(seq[i]>root)
			break;
	}
	//all right child elements should greater than root
	for(j=i;j<n-1;++j)
	{
		if(seq[j]<root)
			return false;
	}
	bool left = true;
	bool right = true;
	if(i>0)
		left = is_postorder(seq,i);
	if(i<n-1)
		right = is_postorder(seq+i,n-1-i);
	return (left && right);//only if both left and right sub trees are postorder
}


#endif