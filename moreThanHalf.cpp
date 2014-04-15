/*
 * @author jdpdyx@126.com
 * @date 2014-03-07
 * @note 找出数组中出现次数超过一半的数
 */
#include <iostream>
#include <vector>

using namespace std;


/**
 * 用于快排的划分函数
 * @param a: 数组
 * @param start: 划分区间的下界
 * @param end: 区间上界
 * @note a[start:end]都是闭区间
 */

int partition(vector<int>& a, size_t start, size_t end)
{
  if (start >= a.size() || end >= a.size()) throw "Index out of range";
  if (start >= end) return end;
  int small = start - 1;
  int pivot = a[end];
  for (size_t i = start; i<end; ++i)
  {
    if (a[i] < pivot)
    {
      swap(a[++small],a[i]);
    }
  }
  swap(a[++small], a[end]);
  return small;
}

/*
 * use partition
 * 找到处于中间位置的那个数
 */
int moreThanHalfNum(vector<int>& a) {
  int length = a.size();
  int middle = length >> 1;
  int start = 0;
  int end = length - 1;
  int cur = partition(a, start, end);
  while(cur != middle)
  {
    if (cur > middle)
    {
      end = cur - 1;
    }
    else {
      start = cur + 1;
    }
    cur = partition(a, start, end);
  }
  return a[middle];
}

/*
 * O(n)
 * 记录当前遇到过的次数最多的数，遇到不同的数，计数减一
 * 遇到相同的数，计数加一；如果计数到零，记录新的数
 */

int moreThanHalfNum_2(vector<int>& a)
{
  if(a.size() < 1) throw "Empty array!";
  int result = a[0];
  int count = 1;
  for (size_t i = 1; i < a.size(); i++) {
    /* code */
    if (count == 0)
    {
      result = a[i];
      count = 1;
    }
    else if(a[i] == result)
    {
      count++;
    }
    else count--;
  }
  return result;
}

int main()
{
  vector<int> a = {1,2,3,2,4,2,2,5};
  cout << moreThanHalfNum(a) << endl;
  cout << moreThanHalfNum_2(a) << endl;
  return 0;
}
