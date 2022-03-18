#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int origin [101][101];

int getOriginVal(int n, int m, int a, int b) {
    if(a <= 0 || a > n || b <= 0 || b > m) {
        return 0;
    }
    return origin[a][b];
}

int main() {
    int n, m;
    int p, q;
    while(~scanf("%d %d %d %d", &n, &m, &p, &q)) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                scanf("%d", &origin[i][j]);
            }
        }
        long long c, d;
        long long newVal;
        for(int a = 1; a <= p; ++a) {
            for(int b = 1; b <= q; ++b) {
                c = a * n / p;
                d = b * m / q;
                newVal = (getOriginVal(n, m, c, d) + 
                getOriginVal(n, m, c, d + 1) + 
                getOriginVal(n, m, c + 1, d) + 
                getOriginVal(n, m, c + 1, d + 1)) / 4;
                printf("%lld ", newVal);
            }
            printf("\n");
        }
    }
}