#include <iostream>
#include <vector>
#include "minStack.h"

using namespace std;

int main()
{
  MinStack<int> ms;
  vector<int> a = {3,2,4,5,1};
  for(size_t i=0; i < a.size(); ++i )
  {
    ms.push(a[i]);
    cout << "push " << a[i] << endl;
    cout << "min " << ms.min() << endl;
  }

  return 0;
}
