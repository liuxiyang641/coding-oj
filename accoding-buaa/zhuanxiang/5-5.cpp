#include<stdio.h>

int main() {
    int scores[101];
    int score;
    int count = 0;
    int sum = 0;
    while(~scanf("%d", &score)) {
        scores[count++] = score;
        sum+=score;
    }
    double avg = sum * 1.0 / count;
    int sumLow = 0, sumHigh = 0;
    int countLow = 0, countHigh = 0;
    for(int i = 0; i < count; ++i) {
        if(scores[i] >= avg) {
            sumHigh += scores[i];
            countHigh++;
        }
        else {
            sumLow += scores[i];
            countLow++;
        }
    }
    if(sum % count == 0) {
        printf("%d %d\n", count, sum / count);
    }
    else {
        printf("%d %.2lf\n", count, avg);
    }
    if(sumHigh % countHigh == 0) {
        printf("%d %d\n", countHigh, sumHigh / countHigh);
    }
    else {
        printf("%d %.2lf\n", countHigh, sumHigh * 1.0 / countHigh);
    }
    if(sumLow % countLow == 0) {
        printf("%d %d\n", countLow, sumLow / countLow);
    }
    else {
        printf("%d %.2lf\n", countLow, sumLow * 1.0 / countLow);
    }
}