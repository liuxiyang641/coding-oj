// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int getMonthDays(int year, int month) {
    int currentMonthDays;
    if(month == 2) {
        currentMonthDays = 28;
        if(year % 4 == 0 && year % 100 != 0) {
            currentMonthDays = 29;
        }
        if(year % 400 == 0) {
            currentMonthDays = 29;
        }
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        currentMonthDays = 31;
    }
    else {
        currentMonthDays = 30;
    }
    return currentMonthDays;
}

int main() {
    int m, n;
    int runYear1900 = 1900 / 4 - 1900 / 100 + 1900 / 400;
    while(scanf("%d %d", &m, &n)!=EOF) {
        int runYear = (m - 1) / 4 - (m - 1) / 100 + (m - 1) / 400; // 注意这里，防止把当前年是闰年的情况加进去
        runYear -= runYear1900;
        int allDays = (365 * (m - 1900)) % 7 + runYear * 1;
        for(int i = 1; i < n; ++i) {
            allDays += (getMonthDays(m, i));
            // allDays %= 7;
        }

        int beginXinqi = allDays % 7 + 1; // 加上1，表示新的一月第一天的星期天
        int spaceCount = beginXinqi % 7;
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");
        for(int i = 0; i < spaceCount; ++i) {
            printf("    ");
        }
        int currentMonthDays = getMonthDays(m, n);
        for(int i = 1; i <= currentMonthDays; ++i) {
            printf("%4d", i);
            if((i + spaceCount) % 7 == 0) {
                printf("\n");
            }
        }
        if((currentMonthDays + spaceCount) % 7 != 0) {
            printf("\n");
        }
    }
}