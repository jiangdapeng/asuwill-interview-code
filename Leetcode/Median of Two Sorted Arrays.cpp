/*
author: jdpdyx@126.com
date: 2014/08/05
blog:  http://www.asuwill.info/programming/152.html
*/
#include <limits>

class Solution {
public:
    int findKthIn(int A[], int na, int start_a, int B[], int nb, int start_b, int k)
    {
        /*
        na: length of array A
        start_a: search start point of array A
        k: the kth number in A[start_a:] + B[start_b:]
        */
        // cout << "k = " << k << endl;
        if (start_a >= na) return B[start_b + k - 1];
        if (start_b >= nb) return A[start_a + k - 1];
        if ( k == 1 )
        {
            return min(A[start_a],B[start_b]);
        }
        int half_k = k/2;
        int next_a = start_a + half_k <= na? A[start_a+half_k -1] : INT_MAX;
        int next_b = start_b + half_k <= nb? B[start_b+half_k -1] : INT_MAX;
        if (next_a < next_b)
        {
            // the kth number is not in A[:start_a + half_k]
            // half_k numbers in A are excluded
            return findKthIn(A,na,start_a + half_k,B,nb,start_b, k - half_k);
        }
        else
        {
            // the kth number is not in B[:start_b + half_k]
            return findKthIn(A,na,start_a, B, nb, start_b + half_k, k - half_k);
        }
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        int len = n + m;
        if (len % 2 == 0)
        {
            // 2 4 6 9
            // return (4 + 6)/2
            return (findKthIn(A,m,0,B,n,0,len/2) + findKthIn(A,m,0,B,n,0,len/2 + 1))/2.0;
        }
        else
        {
            // 2 4 6
            // return 4
            return findKthIn(A,m,0,B,n,0,len/2+1);
        }
    
    }

};
