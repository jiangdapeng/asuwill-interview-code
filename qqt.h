#ifndef QQT_H
#define QQT_H

/*
第6题
------------------------------------
腾讯面试题：   
给你10分钟时间，根据上排给出十个数，在其下排填出对应的十个数   
要求下排每个数都是先前上排那十个数在下排出现的次数。   
上排的十个数如下：   
【0，1，2，3，4，5，6，7，8，9】

初看此题，貌似很难，10分钟过去了，可能有的人，题目都还没看懂。   

举一个例子，   
数值: 0,1,2,3,4,5,6,7,8,9   
分配: 6,2,1,0,0,0,1,0,0,0   
0在下排出现了6次，1在下排出现了2次，   
2在下排出现了1次，3在下排出现了0次....

注意：我这里的做法纯粹是暴利，如果上排的十个数是随意给出，则这种做法不一定有解
*/

#include <vector>

int count(const std::vector<int>& elems,int value)
{
	int rt = 0;
	for(int i=0;i<elems.size();++i)
	{
		if(elems[i] == value)
			rt ++;
	}
	return rt;
}
void qq(const std::vector<int>& firstLine,std::vector<int>& secondLine)
{
	size_t size = firstLine.size();
	secondLine.clear();
	//first, initialize every item of secondLine to 0
	for(int i=0;i<size;++i)
		secondLine.push_back(0);
	bool changed = true;
	while(changed)
	{
		changed = false;
		for(int i=0;i<size;++i)
		{
			int tmp = secondLine[i];
			secondLine[i] = count(secondLine,firstLine[i]);
			if(tmp != secondLine[i])
				changed=true;
		}
	}
}

#endif