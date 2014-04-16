/*
 * @author: asuwill.jdp@gmail.com
 * @description: 让环形仓库库存平均，求最小代价
 * 解法：
 *  data[] :仓库库存情况
 *  avg:平均量
 *  r[i] = data[i] - avg
 *  p[i]：仓库i需要往仓库i+1运输的量，负值表示反方向运输
 *  令 p[0] = x
 *  p[i] = x - t[i] 
 *  其中 t[i] = t[i-1] - r[i]
 *   目标是，最小化 sum(abs(p[i])* distance[i] for all i)
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  vector<float> data;
  float avg = 0;
  float total = 0;
  vector<float> t;

  float tmp = 0;
  while(cin >> tmp)
  {
    total += tmp;
    data.push_back(tmp);
  }

  avg = total / data.size();

  t.resize(data.size());
  t[0] = 0;
  for(int i=1; i<data.size(); ++i)
  {
    t[i] = t[i-1] - (data[i] - avg); // t[i] = t[i-1] - r[i]
  }

  vector<float> st = t;

  sort(st.begin(), st.end());
  float mid = st[st.size()/2]; // 中位数
  float cost = 0;
  for (int i=0; i<data.size(); ++i)
  {
    cost += abs(mid - t[i]);
  }
  cout << "total cost: " << cost << endl;

  return 0;
}
