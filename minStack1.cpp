/*
* @author jdpdyx@126.com
* @date 2014-03-04
* @note push\pop\min的时间复杂度都是O(1)。注意，这个实现不是多线程安全的
*/
#include <stack>

using std::stack;

class MinStack
{
public:
	MinStack(){}
	MinStack(const MinStack& ms)
	{
		vStack = ms.vStack;
		mStack = ms.mStack;
	}
	~MinStack() {}

	void push(int v)
	{
		vStack.push(v);
		if (mStack.empty())
		{
			mStack.push(v); // 第一个元素，肯定是当前最小元素
		}
		else if(v < mStack.top())
		{
			mStack.push(v); // 发现更小的值
		}
		else 
		{
			mStack.push(mStack.top()); // 依然是上一个最小值
		}
	}
	int top()
	{
		if(vStack.empty()) throw "Empty MinStack";
		else return vStack.top();
	}

	void pop()
	{
		vStack.pop();
		mStack.pop();
	}

	int min()
	{
		if(mStack.empty()) throw "Empty MinStack";
		else return mStack.top();
	}

	bool empty()
	{
		return vStack.empty();
	}
private:
	stack<int> vStack; // 正常存储的栈空间
	stack<int> mStack; // 辅助栈空间，用来存储每个阶段的最小值
};

int main()
{
	MinStack ms;
	int a[] = {3,2,4,5,1};
	for(int i:a)
	{
		ms.push(i);
		cout << "push " << i << endl;
		cout << "min " << ms.min() << endl;
	}
	return 0;
}