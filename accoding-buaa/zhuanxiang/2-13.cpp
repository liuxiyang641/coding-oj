// https://accoding.buaa.edu.cn/contest-ng/index.html#/713/problems

#include<stdio.h>
#include<string.h>

int main() {
    char s[1000];
    double a, b;
    while(scanf("%s", s)!=EOF) {
        a = 0;
        b = 0;
        int len = strlen(s);
        int cutPos = 0;
        for(int i = 0; i < len; ++i) {
            if(s[i] == '/') {
                cutPos = i;
                break;
            }
        }
        int i = 0;
        while(s[i] == '0') {
            i++;
        }
        for(; i < cutPos; ++i) {
            a = (s[i] - '0') + a * 10;
        }
        i = cutPos + 1;
        while(s[i] == '0') {
            i++;
        }
        for(; i < len; ++i) {
            b = (s[i] - '0') + b * 10;
        }
        printf("%.2lf\n", a / b);
        // getchar();
    }
}