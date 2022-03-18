#include<stdio.h>
#include<string.h>

int main() {
    int m[11][11];
    int isExisted[101];
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(isExisted, 0, sizeof(isExisted));
        int ans = 0;
        long long n2 = n * n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &m[i][j]);
                if(isExisted[m[i][j]]) {
                    ans = -1;
                }
                if(m[i][j] < 1 || m[i][j] > n2) {
                    ans = -1;
                }
                isExisted[m[i][j]] = 1;
            }
        }
        if(ans == -1) {
            printf("No\n");
            continue;
        }
        long long duiSum1 = 0, duiSum2 = 0;
        for(int i = 0; i < n; ++i) {
            duiSum1 += m[i][i];
            duiSum2 += m[n - 1 - i][i];
        }
        if(duiSum2 != duiSum1) {
            printf("No\n");
        }
        else {
            long long sum;
            for(int i = 0; i < n; ++i) {
                sum = 0;
                for(int j = 0; j < n; ++j) {
                    sum += m[i][j];
                }
                if(sum != duiSum1) {
                    ans = -1;
                    break;
                }
            }
            if(ans == -1) {
                printf("No\n");
                continue;
            }
            for(int i = 0; i < n; ++i) {
                sum = 0;
                for(int j = 0; j < n; ++j) {
                    sum += m[j][i];
                }
                if(sum != duiSum1) {
                    ans = -1;
                    break;
                }
            }
            if(ans == -1) {
                printf("No\n");
                continue;
            }
            printf("Yes\n");
        }
    }
}