#include<stdio.h>
#include<stdlib.h>

void f(int index, int* a, int n, int left, int* ans) {
    if(left == 0) {
        (*ans)++;
        return;
    }
    for(int i = 1; i <= n ; ++i) {
        if(a[i] == 0 && i != index) {
            a[i] = index;
            f(index + 1, a, n, left - 1, ans);
            a[i] = 0;
        }
    }
}

long long f1(int n) {
    if(n == 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }
    return (n - 1) * (f1(n - 2) + f1(n - 1));
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        // int* a = (int*)malloc(sizeof(int) * (n + 1));
        // int* ans = (int*)malloc(sizeof(int));
        // *ans = 0;
        // f(1, a, n, n, ans);
        // printf("%d\n", *ans);
        // free(a);
        // free(ans);
        printf("%lld\n", f1(n));
    }
}