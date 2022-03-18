#include<stdio.h>

int main() {
    int n;
    int a[1000000];

    while(scanf("%d", &n)!=EOF) {
        int count = 0;
        if(n == 0) {
            printf("0\n");
        }
        while(n) {
            a[count++] = n % 3;
            n /= 3;
        }
        if(count >= 5) {
            printf("LONG");
        }
        while(count--) {
            printf("%d", a[count]);
        }
        printf("\n");
    }
}