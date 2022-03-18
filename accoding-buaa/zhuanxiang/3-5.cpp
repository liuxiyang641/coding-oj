// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>
#include<math.h>

int main() {
    double x1, y1, x2, y2, x3, y3, r;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &r)!=EOF) {
        double dis;
        if(x1 == x2) {
            dis = fabs(x3 - x1);
        }
        else {
            double k = (y2 - y1) / (x2 - x1);
            double b = y1 - k * x1;
            dis = fabs(k * x3 - y3 + b) / sqrt(k * k + 1);
        }
        if(fabs(dis - r) < 1.0e-7) {
                printf("1\n");
            }
        else if((dis - r) > 0) {
            printf("0\n");
        }
        else {
            printf("2\n");
        }
    }
}