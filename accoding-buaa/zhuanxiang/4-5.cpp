// https://accoding.buaa.edu.cn/contest-ng/index.html#/715/problems

#include<stdio.h>

int calRunYears(int year) {
    return year / 4 - year / 100 + year / 400;
}

int getMonthDays(int year, int month) {
    if(month == 2) {
        if(year == 0) {
            return 28;
        }
        if(year % 4 == 0 && year % 100 != 0) {
            return 29;
        }
        if(year % 400 == 0) {
            return 29;
        }
        return 28;
    }
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    }
    return 30;
}

void printXinqi(int x) {
    switch(x) {
        case 1:
            printf("Mon\n");
            break;
        case 2:
            printf("Tue\n");
            break;
        case 3:
            printf("Wed\n");
            break;
        case 4:
            printf("Thu\n");
            break;
        case 5:
            printf("Fri\n");
            break;
        case 6:
            printf("Sat\n");
            break;
        case 0:
            printf("Sun\n");
            break;
    }
}

int main() {
    char s[20];
    while(scanf("%s", s)!=EOF) {
        int year, month, day;
        year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
        month = (s[4] - '0') * 10 + (s[5] - '0');
        day = (s[6] - '0') * 10 + (s[7] - '0');
        int pastYears = year;
        int pastDays = pastYears * 365;
        int pastRunYears = calRunYears(year - 1);
        pastDays += pastRunYears;

        for(int i = 1; i < month; ++i) {
            pastDays += getMonthDays(year, i);
        }
        pastDays += day;
        printXinqi(pastDays % 7);
    }
}