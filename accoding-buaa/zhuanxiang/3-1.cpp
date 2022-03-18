// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main() {
    int a[7];
    while(scanf("%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6])!=EOF) {
        int rightCount = 0;
        for(int i = 1; i <= 6; ++i) {
            if(a[i] == i) {
                rightCount++;
            }
        }
        if(rightCount == 0) {
            printf("Sorry!Unlucky!\n");
        }
        else {
            while (rightCount--)
            {
                printf("*");
            }
            printf("\n");
        }
    }
}