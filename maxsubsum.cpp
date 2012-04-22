
/*
3.求子数组的最大和
题目：
输入一个整形数组，数组里有正数也有负数。
数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。
求所有子数组的和的最大值。要求时间复杂度为O(n)。

例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2，
因此输出为该子数组的和18。
*/
#include<iostream>
#include<vector>
using namespace std;

int maxsubsum(const vector<int>& elems)
{
	int maxsum = 0;
	int sum = maxsum;
	for(int i=0;i<elems.size();++i)
	{
		sum+=elems[i];
		maxsum = max(maxsum,sum);
		sum = max(sum,0);
	}
	return maxsum;
}

int main()
{
	vector<int> vi;
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int tmp;
		cin>>tmp;
		vi.push_back(tmp);
	}
	cout<<"maxsum:"<<maxsubsum(vi)<<endl;
	return 0;
}
