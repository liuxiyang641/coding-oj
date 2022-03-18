// https://accoding.buaa.edu.cn/contest-ng/index.html#/713/problems

#include<stdio.h>

int main() {
    double a, b, c;
    while(scanf("%lf%lf%lf", &a, &b, &c)!=EOF) {
        printf("%.1lf\n", a / 3 + b / 3 + c / 3);
    }
}