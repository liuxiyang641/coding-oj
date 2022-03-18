#include<stdio.h>

int main() {
    int len;
    int a[21];
    int b[21];
    while(~scanf("%d", &len)) {
        int tmp;
        for(int i = 0; i < len; ++i) {
            scanf("%d", &a[i]);
        }
        int n;
        scanf("%d", &n);
        for(int i = 0; i < len; ++i) {
            b[(i + n) % len] = a[i];
        }
        for(int i = 0; i < len; ++i) {
            printf("%d ", b[i]);
        }
        printf("\n");
    }
}