

#include<stdio.h>

int f(int m, int n, int x, int y) {
    if(x == 1) return y;
    if(y == n) return n + x - 1;
    if(x == m) return n + m - 2 + (n - y + 1);
    if(y == 1) return n + m + n - 2 + (m - x);

    return f(m - 2, n - 2, x - 1, y - 1) + 2*n + 2*(m-2);
}

int main() {
    int m, n, x, y;
    // scanf("%d %d %d %d", &m, &n, &x, &y);
    // printf("%d\n", f(m, n, x, y));
    while(~scanf("%d %d %d %d", &m, &n, &x, &y)) {
        printf("%d\n", f(m, n, x, y));
    }
}