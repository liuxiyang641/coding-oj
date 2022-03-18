// https://accoding.buaa.edu.cn/contest-ng/index.html#/713/problems

#include<stdio.h>

int isHuo(int n) {
    int left = n / 100;
    int right = n % 100;
    return (left*left + right*right) == n;
}

int main() {
    int allHuo[9999];
    int len = 0;
    allHuo[len++] = 1000;
    for(int i = 1001; i < 9999; ++i) {
        if(isHuo(i)) {
            allHuo[len++] = i;
        }
    }
    int n;
    while(scanf("%d", &n)!=EOF) {
        if(n >= allHuo[len - 1]) {
            printf("-1\n");
        }
        else {
            for(int i = 0; i < len; ++i) {
                if(allHuo[i] > n) {
                    printf("%d\n", allHuo[i]);
                    break;
                }
            }
        }
    }
    return 0;
}