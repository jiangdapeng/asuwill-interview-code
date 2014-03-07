#include <stdio.h>

const int MAXLENGTH=1002;
int len(char* a)
{
  int i=0;
  while(a[i])++i;
  return i;
}
int reverse(char* a)
{
  int n=len(a);
  int tmp=0;
  for(int i=0,j=n-1;i<j;++i,--j)
  {
    tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
  }
  return n;
}


void bignumplus(char* A,char* B,char* C)
{
    int n1=reverse(A);
    int n2=reverse(B);
    int i=0;
    int c=0;
    while(i<n1 && i<n2)
    {
      int m=c+A[i]-'0'+B[i]-'0';
      C[i]=m%10+'0';
      c=m/10;
      ++i;
    }
    while(i<n1)
    {
      int m=c+A[i]-'0';
      C[i]=m%10+'0';
      c=m/10;
      ++i;
    }
    while(i<n2)
    {
      int m=c+B[i]-'0';
      C[i]=m%10+'0';
      c=m/10;
      ++i;
    }
    if(c!=0)
    {
      C[i]=c+'0';
      C[i+1]=0;
    }
    else C[i]=0;
    reverse(C);
}

int main()
{
  int N=0;
  char A[MAXLENGTH];
  char B[MAXLENGTH];
  char C[MAXLENGTH];
  scanf("%d",&N);
  for(int i=0;i<N;++i)
  {
    if(i!=0) printf("\n");
    scanf("%s %s",A,B);
    printf("Case %d:\n",i+1);
    printf("%s + %s = ",A,B);
    bignumplus(A,B,C);
    printf("%s\n",C);
  }
  return 0;
}
