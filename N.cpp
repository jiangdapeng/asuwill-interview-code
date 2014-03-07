#include <stdio.h>
/*
    compute N!
*/
const int SIZE=15000;
const int BASE=10000;
int largeN[SIZE];
int len=0;

void output(int* N,int len)
{
  printf("%d",N[len-1]);
  for(int i=len-2;i>=0;--i)
  {
    printf("%04d",N[i]);
  }
}

void largeMul(int n,int* N)
{
  int carry=0;
  for(int i=0;i<len;++i)
  {
    int tmp=largeN[i]*n+carry;
    carry = tmp/BASE;
    largeN[i]=tmp%BASE;
  }
  if(carry>0)
  {
    largeN[len]=carry;
    len++;
  }
}

void fact(int n)
{
  len=1;
  largeN[0]=1;

  for(int i=1;i<=n;++i)
  {
    largeMul(i,largeN);
  }

}

int main()
{
  int n;
  while(scanf("%d",&n)!=EOF)
  {
    fact(n);
    output(largeN,len);
    printf("\n");
  }
  return 0;
}

