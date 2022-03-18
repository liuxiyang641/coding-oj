// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main(int argc, char* argv) {
    int x;
    while(scanf("%d", &x)!=EOF) {
        int ans;
        if(x < 1) {
            ans = x;
        }
        else if(x >= 1 && x < 10) {
            ans = 2 * x - 3;
        }
        else {
            ans = 3 * x - 5;
        }
        printf("%d\n", ans);
    }
}