// https://accoding.buaa.edu.cn/contest-ng/index.html#/713/problems

#include<stdio.h>

int main() {
    double a, c;
    while(scanf("%lf%lf", &a, &c)!=EOF) {
        printf("%.2lf\n", a + a * c * 0.01);
    }
}