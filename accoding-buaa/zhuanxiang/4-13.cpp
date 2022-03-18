
#include<stdio.h>

int hannuo(int n) {
    if(n == 1) {
        return 2;
    }
    return 3 * hannuo(n - 1) + 2;
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        printf("%d\n", hannuo(n));
    }
}