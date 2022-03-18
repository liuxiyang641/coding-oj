
#include<stdio.h>

void scanfAndPrint() {
    int n;
    if(~scanf("%d", &n)) {
        scanfAndPrint();
        printf("%d\n", n);
    }
}

int main() {
    scanfAndPrint();
}