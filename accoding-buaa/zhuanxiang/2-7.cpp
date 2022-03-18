// https://accoding.buaa.edu.cn/contest-ng/index.html#/713/problems

#include<stdio.h>

int main() {
    long long a;
    while (scanf("%lld", &a)!=EOF)
    {
        printf("%lld\n", (a % 100000007 * 3 % 100000007 + 1) % 100000007);
    }
    
}