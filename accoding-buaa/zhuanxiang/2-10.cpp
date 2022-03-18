// https://accoding.buaa.edu.cn/contest-ng/index.html#/713/problems
#include<stdio.h>

int main() {
    long long n;
    int nums[9];
    while(scanf("%lld", &n)!=EOF) {
        int len = 0;
        long long tmpN = n;
        int newCode = 0;
        for(int i = 0; i < 8; ++i) {
            newCode += ((n % 10) * (2 + i)) % 10;
            n /= 10;
        }
        newCode %= 10;
        printf("%lld%d\n", tmpN, newCode);
    }
}
