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
* 原理：设m’为还需要从A中选取的元素个数， n’为元素a_i及其右边的元素个数， 也即n’=(n-i+1)。那么选取元素a_i的概率为 m’/n’
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
