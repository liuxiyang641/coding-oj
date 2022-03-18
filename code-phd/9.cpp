#include<stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    int a[1000000];
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int flag = 0;
        for(int i = n - 1; i >= 0; --i) {
            flag = 0;
            for(int j = 0; j < i; ++j) {
                if(a[j] < a[i]) {
                    int tmp = a[j];
                    a[j] = a[i];
                    a[i] = tmp;
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                break;
            }
        }
        if(!flag) {
            printf("NONE\n");
            continue;
        }
        for(int i = n - 1; i >= 0; --i) {
            flag = 0;
            for(int j = 0; j < i; ++j) {
                if(a[j] < a[i]) {
                    int tmp = a[j];
                    a[j] = a[i];
                    a[i] = tmp;
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                break;
            }
        }
        if(!flag) {
            printf("NONE\n");
            continue;
        }
        for(int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}