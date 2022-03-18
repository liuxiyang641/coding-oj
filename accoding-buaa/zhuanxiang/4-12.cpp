
#include<stdio.h>

int f(int n, int m) {
    // 对整数n进行划分，保证各项都不大于m
    if(n == 1) {
        return 1; // n是1只有一种划分方法
    }
    if(m == 1) {
        return 1; // 全是1的划分
    }
    if(n == m) {
        return 1 + f(n, m - 1);
    }
    if(n < m) {
        return f(n, n); 
    }
    if(n > m) {
        return f(n - m, m) + f(n, m - 1);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", f(n, n));
    }
}