// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main() {
    int a[13];
    while(scanf("%d", &a[1])!=EOF) {
        for(int i = 2; i <= 12; ++i) {
            scanf("%d", &a[i]);
        }
        int preMoney = 0;
        int errorMonth = 0;
        int allToMom = 0;
        for(int i = 1; i <= 12; ++i) {
            int currentMoney = preMoney + 300;
            if(currentMoney < a[i]) {
                errorMonth = i;
                break;
            }
            int moneyToMom = (currentMoney - a[i]) / 100 * 100;
            allToMom += moneyToMom;
            int leftMoney = currentMoney - a[i] - moneyToMom;
            preMoney = leftMoney;
        }
        if(errorMonth) {
            printf("-%d\n", errorMonth);
        }
        else {
            printf("%d\n", preMoney + (int)(allToMom * 1.2));
        }
    }
}