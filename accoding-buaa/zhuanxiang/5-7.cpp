#include<stdio.h>

int main() {
    int n, m;
    int a[100000], b[100000];
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < m; ++i) {
            scanf("%d", &b[i]);
        }
        int i = 0, j = 0;
        for(; i < n && j < m; ++i, ++j) {
            while(i < n && a[i] != b[j]) {
                i++;
            }
            if(n == i) { // 防止是最后一个没有匹配后，还会额外加1
                break; 
            }
        }
        if(j == m) {
            printf("TAK\n");
        }
        else {
            printf("NIE\n");
        }
    }
}