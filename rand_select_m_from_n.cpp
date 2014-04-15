#include <iostream>
#include "rand_select.h"

using namespace std;

int main()
{
  vector<int> a{1,2,3,4,5,6}; // -std=c++0x
  vector<int> result;
  rand_select(a,2,result);
  for(int i = 0; i< result.size(); ++i){
    cout << result[i] << endl;
  }
  return 0;
}
