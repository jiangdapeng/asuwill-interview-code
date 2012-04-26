#ifndef SUM_EQ_H
#define SUN_EQ_H

#include <iostream>

/*
  第14题：
  题目：输入一个已经按升序排序过的数组和一个数字，
  在数组中查找两个数，使得它们的和正好是输入的那个数字。
  要求时间复杂度是O(n)。如果有多对数字的和等于输入的数字，输出任意一对即可。
  例如输入数组1、2、4、7、11、15和数字15。由于4+11=15，因此输出4和11
 */
void sum_eq(int seq[],int n,int sum)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        if(seq[i]+seq[j] == sum)
        {
            std::cout<<seq[i]<<" "<<seq[j]<<endl;
            break;
        }
        else if(seq[i]+seq[j] < sum)
            ++i;
        else --j;
    }
}

#endif
