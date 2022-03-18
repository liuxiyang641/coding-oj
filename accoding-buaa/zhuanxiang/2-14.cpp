// https://accoding.buaa.edu.cn/contest-ng/index.html#/713/problems

#include<stdio.h>

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        long long a, b;
        int w0, w1, w2, w3;
        scanf("%lld %lld", &a, &b);
        scanf("%d %d %d %d", &w0, &w1, &w2, &w3);
        int s1[34] = {0}, s2[34] = {0};
        int len1 = 0, len2 = 0;
        if(a == 0) {
            len1 = 1;
        }
        if(b == 0) {
            len2 = 1;
        }
        while(a) {
            s1[len1++] = a % 2;
            a /= 2;
        }
        while(b) {
            s2[len2++] = b % 2;
            b /= 2;
        }
        
        int maxLen = len1 > len2 ? len1 : len2;
        int ans [34];
        for(int i = 0; i < maxLen; ++i) {
            if(s1[i] == 0) {
                if(s2[i] == 0) {
                    ans[i] = w0;
                }
                else {
                    ans[i] = w1;
                }
            }
            else {
                if(s2[i] == 0) {
                    ans[i] = w2;
                }
                else {
                    ans[i] = w3;
                }
            }
        }
        long long ans10 = 0;
        int i = maxLen - 1;
        while(ans[i] == 0) {
            i--;
        }
        for(; i >= 0; --i) {
            ans10 = ans10 * 2 + ans[i];
        }
        printf("%lld\n", ans10);
    }
}