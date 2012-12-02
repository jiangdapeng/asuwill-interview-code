#!/usr/bin/env python
# coding=utf8

"""
calculate edit distance
of two string
"""
def editdist(s1,s2):
    """
    dynamic programming
    """
    n1=len(s1)
    n2=len(s2)
    d=[[0 for j in range(n2+1)] for i in range(n1+1)]
    for i in range(1,n1+1):
        d[i][0]=i
    for i in range(1,n2+1):
        d[0][i]=i
    for i in range(1,n1+1):
        for j in range(1,n2+1):
            if s1[i-1]==s2[j-1]:
                dd=0
            else:
                dd=1
            d[i][j]=min(d[i-1][j-1]+dd,min(d[i-1][j]+1,d[i][j-1]+1))
    return d[n1][n2]

