#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b) {
    int x1 = *((int*)a);
    int x2 = *((int*)b);
    if(abs(x1) != abs(x2)) {
        return abs(x1) - abs(x2);
    }
    else {
        if(x1 < 0 && x2 >= 0) {
            return -1; // 输出-1代表a在前
        }
        else if(x1 >=0 && x2 < 0) {
            return 1;
        }
        else {
            return abs(x1) - abs(x2);
        }
    }
}

int main() {
    int n;
    int a[101];
    while(~scanf("%d", &n)) {
        for(int i = 0;i < n; ++i) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp);
        for(int i = 0;i < n; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}