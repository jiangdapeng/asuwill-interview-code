#ifndef __RAND_SELECT__
#define __RAND_SELECT__
#include <vector>
#include <cstdlib>

float frand()
{
  return ((float)rand()) / RAND_MAX;
}

/*
* 从给定数据集中随机选择m个
* 保证每一个数被选到的概率一样
*/
template<class T>
bool rand_select(const std::vector<T> vecData, int m, std::vector<T>& vecRand)
{
    size_t nSize = vecData.size();
    if(nSize  < m || m < 0)
      return false;

    vecRand.clear();
    vecRand.reserve(m);
    for(size_t i = 0, rest= nSize; i < nSize; i++){
      float fRand = frand();
      if(fRand <=(float)(m)/rest){
          vecRand.push_back(vecData[i]);
          m--;
      }
      rest--;
    }
    return true;
}

#endif
