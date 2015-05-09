#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int stamp2sec(const string& stamp) {
  int hours = stamp[0] - '0';
  hours = hours * 10 + stamp[1] - '0';
  
  int min = stamp[3] - '0';
  min = min * 10 + stamp[4] - '0';

  int sec = stamp[6] - '0';
  sec = sec * 10 + stamp[7] - '0';

  return hours * 3600 + min * 60 + sec;
}

string sec2stamp(int sec) {
  int hours = sec / 3600;
  sec = sec % 3600;
  int min = sec / 60;
  sec = sec % 60;
  char buf[10];
  sprintf(buf,"%02d:%02d:%02d",hours,min,sec);
  return string(buf);
}

int main() {
  int n;
  char func[256];
  char timestamp[10];
  char action[10];
  bool valid = true;
  stack<string> s;
  map<string,int> func_start_time;
  map<string,int> func_cost;
  vector<string> call_seq;
  scanf("%d",&n);
  for(int i=0;i<n;++i) {
    scanf("%s%s%s",func,timestamp,action);
    string strf(func);
    string strtime(timestamp);
    string straction(action);
    if (straction == "START") {
      s.push(strf);
      call_seq.push_back(strf);
      func_start_time[strf] = stamp2sec(strtime);
    }
    else if(straction == "END") {
      if (s.top() != strf) {
        // error
        valid = false;
        break;
      }
      else {
        s.pop();
        int end_time = stamp2sec(strtime);
        func_cost[strf] = end_time - func_start_time[strf];
      }
    }
    else {
      // error
      valid = false;
      break;
    }
  }
  if (valid) {
    // output
    for(int i=0;i<call_seq.size();++i) {
      printf("%s %s\n",call_seq[i].c_str(),sec2stamp(func_cost[call_seq[i]]).c_str());
    }
  }
  else {
    printf("Incorrect performance log\n");
  }
  return 0;
}
