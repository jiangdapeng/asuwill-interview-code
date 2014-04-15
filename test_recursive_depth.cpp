/*
* @author: asuwill.jdp@gmail.com
* @description: 测试机器上递归调用栈的大小
*/

#include <iostream>
using namespace std;

int global_count = 0;

int add(int n, int& count) {
  count++;
  cout << "count = " << count << endl;
  if (n == 0) return 0;
  return n + add(n-1, count);
}

void empty_recursive()
{
  global_count++;
  cout << "global_count " << global_count << endl;
  empty_recursive();
}

int main(int args, char** argv){
  int n = 1000000;
  int count = 0;
  if (args == 2) 
  {
    n = atoi(argv[1]);
  }
  cout << add(n, count) << endl;

  empty_recursive();
  return 0;
}
