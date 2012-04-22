#ifndef MIN_K_H
#define MIN_K_H

/*
5.查找最小的k个元素
题目：输入n个整数，输出其中最小的k个。
例如输入1，2，3，4，5，6，7和8这8个数字，则最小的4个数字为1，2，3和4。
*/
#include <vector>
#include <algorithm>

///solution 1: sort -n | head -k
///time complexity:O(nlogn)
/*
* @param [i] elems:source data array
* @param [i] n:number of data item
* @param [i] k:get k minimun item
* @param [o] result:the k minimun item
*/
void mink(const std::vector<int>& elems,int n,int k,std::vector<int> & result)
{
	std::vector<int> temp(elems);
	std::sort(temp.begin(),temp.end());//quick sort
	for(int i=0;i<k;++i)
		result.push_back(temp[i]);
}

///solution 2: bulid a min-heap,then delete k item
///time complexity:O((n/2+k)logn)
void buttomup(int elems[],int i)
{
	int tmp = elems[i];
	while(i/2>0 && elems[i/2]>tmp)
	{
		elems[i]=elems[i/2];
		i/=2;
	}
	elems[i] = tmp;
}

void topdown(int elems[],int n,int i)
{
	int j,min;
	int tmp = elems[i];
	while((i*2)<n)
	{
		j = i*2;
		min = elems[j];
		if(j+1<=n && min>elems[j+1])
		{
			j+=1;
			min = elems[j];
		}
		if(min<tmp)
			elems[i] = min;
		else 
			break;
		i=j;
	}
	elems[i] = tmp;
}

int min(int elems[],int n)
{
	int rt = elems[1];
	elems[1] = elems[n--];
	topdown(elems,n,1);
	return rt;
}
void buildheap(int elems[],int n)
{
	for(int i=n;i>=n/2;--i)
	{
		buttomup(elems,i);
	}
}
void mink(int elems[],int n,int k,int result[])
{
	//note result should be allocated out of this function
	int* minheap = new int[n+1];//a copy of elems
	for(int i=0;i<n;++i)
		minheap[i+1] = elems[i];
	buildheap(minheap,n);
	for(int i=0;i<k;++i)
		result[i] = min(minheap,n--);
	delete[] minheap;
}

#endif