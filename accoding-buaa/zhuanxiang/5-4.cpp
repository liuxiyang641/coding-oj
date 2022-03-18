#include<stdio.h>

int main() {
    int a1, a2;
    int n;
    int customers[1000000];
    while(scanf("%d", &n)!=EOF) {
        a1 = a2 = 0;
        int customer;
        int isSuccess = 1;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &customers[i]);
        }
        for(int i = 0; i < n; ++i) {
            customer = customers[i];
            if(customer == 1) {
                a1++;
                continue;
            }
            if(customer == 2) {
                if(a1 > 0) {
                    a1--;
                    a2++;
                    continue;
                }
                else {
                    isSuccess = 0;
                    break;
                }
            }
            if(customer == 5) {
                if(a2 >= 2) {
                    // 支付2+2
                    a2 -= 2;
                    continue;
                }
                if(a2 >= 1 && a1 >= 2) {
                    // 支付2+1+1
                    a2--;
                    a1-=2;
                    continue;
                }
                if(a1 >= 4) {
                    a1-=4;
                    continue;
                }
                isSuccess = 0;
                break;
            }
        }
        if(isSuccess) {
            printf("Survived\n");
        }
        else {
            printf("Bankrupted\n");
        }
    }
}