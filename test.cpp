#include <iostream>

// range heap example
#include <algorithm>
#include <vector>
using namespace std;

/*
//test reverse_list.h
#include "reverselist.h"
int main()
{
	List* head = buildList();
	display(head);
	head = reverse_list(head);
	display(head);
	head = reverse_list_r(head);
	display(head);
	freeList(head);
}
*/

/*
int main () {
  int myints[] = {10,20,30,5,15};
  vector<int> v(myints,myints+5);

  make_heap (v.begin(),v.end());
  cout << "initial max heap   : " << v.front() << endl;

  pop_heap (v.begin(),v.end()); v.pop_back();
  cout << "max heap after pop : " << v.front() << endl;

  v.push_back(99); push_heap (v.begin(),v.end());
  cout << "max heap after push: " << v.front() << endl;

  sort_heap (v.begin(),v.end());

  cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++) cout << " " << v[i];

  cout << endl;

  return 0;
}
*/


/*
// test list_intersect.h
#include "list_intersect.h"

int main()
{
	List* head1 = buildList(false);
	List* head2 = buildList(true);
	List* s1=NULL;
	bool b1 = is_circle_exists(head1,s1);
	bool b2 = is_circle_exists(head2,s1);
	if(b1)
		cout<<"list1 has circle"<<endl;
	if(b2)
		cout<<"list2 has circle"<<endl;
	bool b3 = is_intersect(head1,head2);
	if(!b3)
		cout<<"list1 and list2 not intersected"<<endl;

	List* tmp2 = head1;
	while(tmp2 && tmp2->m_pNext)
		tmp2 = tmp2->m_pNext;
	tmp2->m_pNext = s1;
	b3 = is_intersect(head1,head2);
	if(!b3)
		cout<<"list1 and list2 not intersected"<<endl;
	else
		cout<<"intersected"<<endl;
}
*/
/*
//test qqt.h
#include "qqt.h"
int main()
{
	vector<int> vi(10);
	for(int i=0;i<10;++i)
	{
		vi[i]=i;
	}
	vector<int> result;
	qq(vi,result);
	for(int i=0;i<10;++i)
		cout<<result[i]<<" ";
}
*/

/*
//test mink.h
#include "mink.h"

int main()
{
	int n;
	int k;
	int arr[10];
	int result[10];
	while(true)
	{
		cin>>n;
		if(n==0)
			break;
		cin>>k;
		for(int i=0;i<n;++i)
		{
			cin>>arr[i];
		}
		mink(arr,n,k,result);
		for(int i=0;i<k;++i)
			cout<<result[i]<<" ";
		cout<<endl;
	}

}
*/

/*
//test findpath.h
#include "findpath.h"

int main()
{
	int n;
	int value;
	while(true)
	{
		cin >> n;
		if(n == 0)
			break;
		cin>>value;
		BSTreeNode* root = buildTree(n);
		findpath(root,value);
		freeList(bt2list(root));
	}

}
*/

/*
//test maxsubsum.h
#include"maxsubsum.h"
int main()
{
	stack<int> si;
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
*/

/*
//test bt2list.h
#include "bt2list.h"
int main()
{
	int n;
	cin>>n;
	BSTreeNode* root = buildTree(n);
	visitTree(root);
	root = remove(root,3);
	visitTree(root);
	BSTreeNode* list = bt2list(root);
	display(list);
	freeList(list);
}
*/