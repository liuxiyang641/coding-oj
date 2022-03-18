#include<stdio.h>

int f(int m, int n) {
    if(m == 0) {
        return n + 1;
    }
    if(m > 0 && n == 0) {
        return f(m - 1, 1);
    }
    if(m > 0 && n > 0) {
        return f(m - 1, f(m, n - 1));
    }
}

int main() {
    int m, n;
    while(~scanf("%d %d", &m, &n)) {
        printf("%d\n", f(m, n));
    }
}