
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
    double n;
    while(scanf("%lf", &n)!=EOF) {
        double x, y;
        double rightY;
        long long in = 0, all = 0;
        for(int i = 0; i < 30000000; ++i) {
            x = 1.0 * rand() / RAND_MAX * n;
            y = 1.0 * rand() / RAND_MAX * 2.0 - 1.0;
            all++;
            rightY = sin(x * x);
            if(rightY <= 0) {
                if(y <= 0 && rightY <= y) {
                    in++;
                }
            }
            else {
                if(y > 0 && rightY >= y) {
                    in++;
                }
            }
        }
        printf("%.2lf\n", 2.0 * n * (1.0 * in / all));
    }
}