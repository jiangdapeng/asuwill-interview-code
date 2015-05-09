//
//  main.cpp
//  mstest
//
//  Created by 江大鹏 on 14/10/19.
//  Copyright (c) 2014年 江大鹏. All rights reserved.
//

#include <iostream>
#include <cstdio>

const int MAX_SIZE = 10000001;
char str[MAX_SIZE];


int main(int argc, const char * argv[]) {
    // insert code here...
    int testcase = 0;
    int n = 0;
    scanf("%d",&testcase);
    for(int r=0;r<testcase;++r) {
        scanf("%d",&n);// string length
        scanf("%s",str);
        bool found = false;
        char cur,pre = ' ';
        int count[3];
        int k = -1;
        for(int i=0;i<3;++i) count[i] = 0;
        for(int i=0;i<n;++i) {
            cur = str[i];
            if(cur != pre) {
                if(pre == ' ' || cur - pre == 1) {
                    k++;
                    pre = cur;
                    count[k] = 1;
                }
                else {
                    pre = cur;
                    k = -1;
                    for(int j=0;j<3;++j) count[j] = 0;
                }
            }
            else {
                count[k]++;
            }
            
            if(k==2) {
                if (count[0]>=count[1] && count[2]>=count[1]) {
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }
    return 0;
}

