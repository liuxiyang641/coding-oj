#include<stdio.h>

int isZhi[10000001];

int main() {
    for(int i = 0; i < 10000001; ++i) {
        isZhi[i] = 1;
    }
    isZhi[1] = isZhi[0] = 0;
    for(int i = 2; i < 10000001; ++i) {
        if(isZhi[i]) {
            for(int j = 2; i * j < 10000001; ++j) {
                isZhi[i * j] = 0;
            }
        }
    }
    int n;
    while(~scanf("%d", &n)) {
        int ans = 0;
        for(int i = 2; i <= n; ++i) {
            if(isZhi[i]) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}