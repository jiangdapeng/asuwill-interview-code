#!/usr/bin/env python
# -*-coding=utf8-*-

import sys

def minhashing(M,hash_func_list):
    """
    M : the origin matrix, each column represents
        a object
    hash_func_list : a list of hash functions
    """
    k=len(hash_func_list)
    m=len(M)
    n=len(M[0])
    SIG=[[sys.maxint for j in range(n)] for i in range(k)]
    for r in range(m):
        h=[hash_func_list[i](r) for i in range(k)]
        for c in range(n):
            if M[r][c] == 1:
                for i in range(k):
                    SIG[i][c]=min(SIG[i][c],h[i])
    return SIG

def test():
    def hash1(x):
        return (x+1)%5
    def hash2(x):
        return (3*x+1)%5
    hash_func_list=[hash1,hash2]
    """
    row s1 s2 s3 s4
    0   0   0  1  0
    1   0   0  1  0
    2   1   0  0  1
    3   1   0  1  1
    4   0   1  0  1
    """
    M=[[0,0,1,0], [0, 0, 1, 0], [1, 0, 0, 1], [0, 1, 0, 1]]
    sig=minhashing(M,hash_func_list)
