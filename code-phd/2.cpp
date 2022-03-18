#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    long long k;
    while(~scanf("%lld", &k)) {
        printf("%lld\n", k);
        if(k == 1) {
            continue;
        }
        for(int i = 1; i < 100; ++i) {
            if(k % 2 == 0) {
                k /= 2;
            }
            else {
                k = 3 * k + 1;
            }
            printf("%lld\n", k);
            if(k == 1) {
                break;
            }
        }
    }
}