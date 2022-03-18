// https://accoding.buaa.edu.cn/contest-ng/index.html#/713/problems

#include<stdio.h>

int main() {
    long long n;
    int nums[100];
    while(scanf("%lld", &n)!=EOF) {
        if(n == 0) {
            printf("0\n");
            continue;
        }
        int len = 0;
        while(n) {
            nums[len++] = n % 10;
            n /= 10;
        }
        if(len < 4) {
            for(int i = 0; i < len; i++) {
                if(nums[i] !=0) {
                    printf("%d", nums[i]);
                }
            }
            for(int i = len; i < 4; i++) {
                printf("0");
            }
            printf("\n");
        }
        else {
            for(int i = len - 1; i > 3; --i) {
                printf("%d", nums[i]);
            }
            for(int i = 0; i < 4; i++) {
                printf("%d", nums[i]);
            }
            printf("\n");
        }
    }
}