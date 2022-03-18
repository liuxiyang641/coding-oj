#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    long long n, x;
    while(~scanf("%lld %lld", &n, &x)) {
        long long tmp;
        while(n--) {
            scanf("%lld", &tmp);
            if(tmp <= x) {
                if(tmp <= x / 2) {
                    x += tmp;
                }
                else {
                    x += tmp % 2 == 0 ? tmp / 2 : (tmp - 1) / 2;
                }
            }
        }
        printf("%lld\n", x);
    }
}