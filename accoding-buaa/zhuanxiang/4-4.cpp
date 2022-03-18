// https://accoding.buaa.edu.cn/contest-ng/index.html#/715/problems

#include<stdio.h>

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    int T;
    scanf("%d", &T);
    int a, b, c, d;
    while(T--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        long long x = a * d + c * b;
        long long y = b * d;
        int z = gcd(x, y);
        x /= z;
        y /= z;
        printf("%lld %lld\n", x, y);
    }
    
}