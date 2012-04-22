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
