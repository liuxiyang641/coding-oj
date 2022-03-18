// https://accoding.buaa.edu.cn/contest-ng/index.html#/715/problems

#include<stdio.h>
#include<math.h>

int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        if(n == 0 || n == 1 || n < 0) {
            printf("no\n");
            continue;
        }
        double sq = sqrt(n);
        int issushu = 1;
        for(int i = 2; i <= sq; ++i) {
            if(n % i == 0) {
                issushu = 0;
                break;
            }
        }
        if(issushu) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
}