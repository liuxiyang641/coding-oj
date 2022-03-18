// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main() {
    long long a[51];
    a[1] = 1;
    a[2] = 1;
    for(int i = 3; i <= 50; ++i) {
        a[i] = 2 * a[i - 2] + a[i - 1];
    }
    int n;
    while(scanf("%d", &n)!=EOF) {
        printf("%lld\n", a[n]);
    }
}