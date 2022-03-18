// https://accoding.buaa.edu.cn/contest-ng/index.html#/713/problems

#include<stdio.h>

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF) {
        int ans = a / b;
        if(a%b != 0) {
            ans++;
        }
        printf("%d\n", ans);
    }
}