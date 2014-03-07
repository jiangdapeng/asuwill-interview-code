#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::swap;
using std::cout;
using std::endl;

vector<string> per(const string& s)
{
  string str = s;
  vector<string> result;
  if (str.size() == 0) return result;
  if (str.size() == 1)
  {
    result.push_back(str);
    return result;
  }
  else
  {
    char first;
    for(size_t i=0; i<str.size(); ++i)
    {
      swap(str[0],str[i]);
      first = str[0];
      vector<string> tmp = per(str.substr(1));

      swap(str[0],str[i]);

      for(size_t j=0;j<tmp.size();++j)
      {
        result.push_back(tmp[j]+first);
      }
    }
    return result;
  }
}

int main()
{
  vector<string> result = per("abcdefgh");
  for(size_t i = 0; i< result.size(); ++i)
  {
    cout << result[i].c_str() << endl;
  }
  return 0;
}
