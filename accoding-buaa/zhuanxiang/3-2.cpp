// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main() {
    int num[3];
    while(scanf("%d%d%d", &num[0], &num[1], &num[2])!=EOF) {
        for(int i = 1; i <= 2; ++i) {
            for(int j = 0; j < 2; ++j) {
                if(num[j + 1] < num[j]) {
                    int tmp = num[j + 1];
                    num[j + 1] = num[j];
                    num[j] = tmp;
                }
            }
        }
        printf("%d\n", num[1]);
    }
}