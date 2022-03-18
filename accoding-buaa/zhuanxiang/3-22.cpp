// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main() {
    int n;
    int iszhishu[1000000] = {1};
    for(int i = 0; i < 1000000; ++i) {
        iszhishu[i] = 1;
    }
    iszhishu[0] = 0;
    iszhishu[1] = 0;
    for(int i = 2; i < 1000000; ++i) {
        if(iszhishu[i]) {
            for(int j = 2; j * i < 1000000; ++j) {
                iszhishu[j * i] = 0;
            }
        }
    }
    while(scanf("%d", &n)!=EOF) {
        for(int i = 2; i <= n; ++i) {
            if(iszhishu[i]) {
                while(n % i == 0) {
                    printf("%d", i);
                    n /= i;
                    if(n) {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
}