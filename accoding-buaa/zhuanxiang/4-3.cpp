// https://accoding.buaa.edu.cn/contest-ng/index.html#/715/problems

#include<stdio.h>

double cal(double x, int m) {
    double ans = 1;
    for(int i = 1; i <= 2 * m; ++i) {
        ans *= x / i;
    }
    double sym = (m % 2 == 0) ? 1 : -1;
    return ans * sym;
}

int main() {
    double x;
    int m;
    while(scanf("%lf %d", &x, &m)!=EOF) {
        double sum = 1;
        for(int i = 2; i <= m; ++i) {
            sum += cal(x, i - 1);
        }
        printf("%.8lf\n", sum);
    }
}