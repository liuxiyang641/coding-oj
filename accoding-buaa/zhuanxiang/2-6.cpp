// https://accoding.buaa.edu.cn/contest-ng/index.html#/713/problems

#include<stdio.h>

int main() {
    double pi = 3.14;
    double h, r;
    while(scanf("%lf%lf", &r, &h)!=EOF) {
        printf("Area = %.3lf\n", pi * r * r * 2 + 2 * pi * r * h);
    }
}