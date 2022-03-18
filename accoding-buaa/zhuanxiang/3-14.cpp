// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>
#include<math.h>

int main() {
    int x, y;
    while(scanf("%d %d", &x, &y)!=EOF) {
        double pi = 3.14159265;
        double theta = atan(fabs((y * 1.0) / x)) * 180 / pi;
        if(x == 0 && y == 0) {
            printf("Bingo\n");
            continue;
        }
        if(x == 0) {
            if(y > 0) {
                printf("N\n");
            }
            else {
                printf("S\n");
            }
            continue;
        }
        if(y == 0) {
            if(x > 0) {
                printf("E\n");
            }
            else {
                printf("W\n");
            }
            continue;
        }
        if(x > 0) {
            if(y > 0) {
                // 第一象限
                printf("NE%.2lf\n", 90 - theta);
            }
            else {
                // 第四象限
                printf("SE%.2lf\n", 90 - theta);
            }
        }
        else {
            if(y > 0) {
                // 第二象限
                printf("NW%.2lf\n", 90 - theta);
            }
            else {
                // 第三象限
                printf("SW%.2lf\n", 90 - theta);
            }
        }
    }
}