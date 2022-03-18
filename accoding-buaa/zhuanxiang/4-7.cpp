// https://accoding.buaa.edu.cn/contest-ng/index.html#/715/problems

#include<stdio.h>

int main() {
    int a [101];
    // for(int i = 1; i <= 100; ++i) {
    //     a[i] = 0;
    // }
    for(int i = 1; i  <= 4; ++i) {
        a[i] = 1;
    }
    // a[5] = 2;
    for(int i = 5; i <= 100; ++i) {
        a[i] = (a[i - 4] + a[i - 1]) % 10000007;
    }
    int n;
    while(scanf("%d", &n)!=EOF) {
        printf("%d\n", a[n]);
    }
}