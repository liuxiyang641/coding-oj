// https://accoding.buaa.edu.cn/contest-ng/index.html#/713/problems

#include<stdio.h>
#include<string.h>

int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        if(n % 7 == 0) {
            printf("g\n");
        }
        else {
            printf("%c\n", n % 7 - 1 + 'a');
        }
    }
}