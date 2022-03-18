// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    long long n;
    while(T--) {
        scanf("%lld", &n);
        int oneCount = 0;
        while(n) {
            if(n % 2 == 1) {
                oneCount++;
            }
            n /= 2;
        }
        if(oneCount == 1) {
            printf("222\n");
        }
        else {
            printf("%d\n", oneCount);
        }
    }
}