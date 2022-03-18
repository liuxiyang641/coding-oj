#include<stdio.h>

double a [101];

double cal(int i, int n, int left) {
    if(left == 0) {
        return 1.0;
    }
    if((n - i) + 1 < left) {
        return 0.0;
    }
    if(left == (n - i) + 1 ) {
        double ans = 1.0;
        for(int j = i; j <= n; ++j) {
            ans *= a[j];
        }
        return ans;
    }
    return a[i] * cal(i + 1, n, left - 1) + (1 - a[i]) * cal(i + 1, n, left);
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%lf", &a[i]);
        }
        double ans = 0;
        for(int i = (n / 2) + 1; i <= n; ++i) {
            ans += cal(1, n, i);
        }
        printf("%.3lf\n", ans);
    }
}