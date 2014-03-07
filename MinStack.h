/*
* @author jdpdyx@126.com
* @date 2014-03-04
* @note push\pop\min的时间复杂度都是O(1)。注意，这个实现不是多线程安全的
* @思路：使用一个辅助栈来保存每一个阶段的最小值
*/

#include <stack>
#include <functional>

using std::stack;
using std::less;

template<typename T, typename Comparator = less<T> >
class MinStack
{
public:
  explicit MinStack(Comparator c = Comparator());
  MinStack(const MinStack<T, Comparator>& ms);

  void push(const T& v);

  T top();

  void pop();

  T min();

  bool empty();

  size_t size();

private:
  stack<T> vStack;
  stack<T> mStack;

  Comparator m_cmp;
};

template<typename T, typename Comparator>
MinStack<T, Comparator>::MinStack(Comparator c):
  m_cmp(c)
{
}

template<typename T, typename Comparator>
MinStack<T,Comparator>::MinStack(const MinStack<T,Comparator>& ms):
  vStack(ms.vStack),mStack(ms.mStack),m_cmp(ms.m_cmp)
{
}

template<typename T, typename Comparator>
void MinStack<T,Comparator>::push(const T& v)
{
  vStack.push(v);
  if (mStack.empty())
  {
    mStack.push(v); // 第一个元素，肯定是当前最小元素
  }
  else if(m_cmp(v ,mStack.top()))
  {
    mStack.push(v); // 发现更小的值
  }
  else
  {
    mStack.push(mStack.top()); // 依然是上一个最小值
  }
}

template<typename T, typename Comparator>
T MinStack<T, Comparator>::top()
{
  if(vStack.empty()) throw "Empty MinStack";
  else return vStack.top();
}

template<typename T, typename Comparator>
void MinStack<T, Comparator>::pop()
{
  vStack.pop();
  mStack.pop();
}

template<typename T, typename Comparator>
T MinStack<T, Comparator>::min()
{
  if(mStack.empty()) throw "Empty MinStack";
  else return mStack.top();
}

template<typename T, typename Comparator>
bool MinStack<T, Comparator>::empty()
{
  return vStack.empty();
}

template<typename T, typename Comparator>
size_t MinStack<T, Comparator>::size()
{
  return vStack.size();
}
