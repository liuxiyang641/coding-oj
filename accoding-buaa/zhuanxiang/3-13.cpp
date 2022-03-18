// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>
#include<string.h>

int compareTime(int hour, int minute, char* targetTime) {
    int targetHour, targetMinute;
    sscanf(targetTime, "%d:%d", &targetHour, &targetMinute);
    if(hour < targetHour) {
        printf("%s\n", targetTime);
        if(hour == targetHour && minute <= targetMinute) {
            printf("%s\n", targetTime);
            return 1;
        }
    }
    else if(hour == targetHour) {
        if(minute <= targetMinute) {
            printf("%s\n", targetTime);
            return 1;
        }
    }
    return 0;
}

int main() {
    char spareTime[10], time1[10], time2[10], time3[10];
    while(scanf("%s", spareTime)!=EOF) {
        int spareHour, spareMinute;
        sscanf(spareTime, "%d:%d", &spareHour, &spareMinute);
        int arriveMinute = (spareMinute + 40) % 60;
        int arriveHour = (spareMinute + 40) / 60 + spareHour;

        scanf("%s", time1);
        scanf("%s", time2);
        scanf("%s", time3);

        int flag = 0;
        flag |= compareTime(arriveHour, arriveMinute, time1);
        flag |=  compareTime(arriveHour, arriveMinute, time2);
        flag |=  compareTime(arriveHour, arriveMinute, time3);
        if(!flag) {
            printf("NO!\n");
        }
    }
}