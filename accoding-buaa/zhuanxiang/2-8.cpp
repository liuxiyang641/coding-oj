// https://accoding.buaa.edu.cn/contest-ng/index.html#/713/problems

#include<stdio.h>

int main() {
    long long n;
    while(scanf("%lld", &n)!=EOF) {
        int countPos = 1;
        int ans = 0;
        while(n) {
            ans += countPos * (n % 10);
            countPos++;
            n = n / 10;
        }
        printf("%lld\n", ans);
    }
}