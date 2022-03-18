// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>
#include<math.h>

int main() {
    long long a, b, c;
    while(scanf("%lld %lld %lld", &a, &b, &c)!=EOF) {
        if(fabs(a) < 1e-12) {
            // 此时方程不再是一元二次
            if(fabs(b) < 1e-12) {
                printf("NO Solution\n");
            }
            else {
                printf("%.2lf\n", - b * 1.0 / c);
            }
            continue;
        }
        double right = (b * 1.0 / c) * (b * 1.0 / c) * (1.0 / 4) - (a * 1.0) / c;
        if(right == 0) {
            printf("%.2lf\n", - (b * 1.0) / (2 * c));
        }
        else if(right < 0) {
            printf("NO Solution\n");
        }
        else {
            double sq = sqrt(right);
            double x1 = sq - (b * 1.0) / (2 * c);
            double x2 = - sq - (b * 1.0) / (2 * c);
            printf("%.2lf %.2lf\n", x2, x1);
        }
    }
}