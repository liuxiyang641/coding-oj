// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int hour = n % 12;
        double second = hour * 30 / (11.0/120.0);
        int minute = second / 60;
        second = second - minute * 60;
        if(minute == 60) {
            hour++;
            hour %= 12;
            minute = 0;
        }
        printf("%d:%d:%.7lf\n", hour, minute, second);
    }
}