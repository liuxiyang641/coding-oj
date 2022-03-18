#include<stdio.h>

int main() {
    int a[501];
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; ++i) {
            int onlyOnce = 1;
            for(int j = 0; j < n; ++j) {
                if(a[i] == a[j] && i != j) {
                    onlyOnce = 0;
                    break;
                }
            }
            if(onlyOnce) {
                printf("%d\n", a[i]);
                break;
            }
        }
    }
}