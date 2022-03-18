// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main() {
    int ans[25];
    ans[0] = 1;
    long long mult = 1;
    int accmEvenTail = 1;
    int preTailZero = 0;
    for(int i = 1; i <= 24; ++i) {
        mult *= i;
        // 统计新出现的0
        int newTailZero = 0;
        // 这一步消掉所有0，防止越界
        while(mult % 10 == 0) {
            mult /= 10;
            newTailZero++;
        }
        if((preTailZero + newTailZero) % 2 == 0) {
            accmEvenTail++;
        }
        preTailZero += newTailZero;
        ans[i] = accmEvenTail;
    }

    int n;
    while (scanf("%d", &n)!=EOF)
    {
        printf("%d\n", ans[n]);
    }
    
}