#include"MinStack.h"
#include<iostream>
using namespace std;

int main()
{
	MinStack<int> msi;
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int tmp;
		cin>>tmp;
		msi.push(tmp);
		cout<<"min:"<<msi.min()<<endl;
	}
	while(!msi.empty())
	{
		cout<<msi.top()<<endl;
		msi.pop();
	}
}
