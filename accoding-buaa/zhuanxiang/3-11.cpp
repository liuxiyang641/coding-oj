// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main() {
    char op;
    double x, y;
    while(scanf("%c %lf %lf", &op, &x, &y)!=EOF) {
        double ans = 0;
        if(op == '/' && y == 0) {
            printf("invalidexpression\n");
            continue;
        }
        switch (op)
        {
        case '+':
            ans = x + y;
            break;
        case '-':
            ans = x - y;
            break;
        case '*':
            ans = x * y;
            break;
        case '/':
            ans = x / y;
            break;
        default:
            break;
        }
        printf("%.2lf\n", ans);
    }
}