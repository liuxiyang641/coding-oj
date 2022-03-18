// https://accoding.buaa.edu.cn/contest-ng/index.html#/715/problems

#include<stdio.h>
#include<math.h>

int main() {
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c)!=EOF) {
        // 判断两边之和大于第三边
        if(a + b > c && abs(a - b) < c) {
            if(a + c > b && abs(a - c) < b) {
                if(b + c > a && abs(b - c) < a) {
                    if(a == b && a == c) {
                        printf("equilateral triangle!\n");
                    }
                    else if(a == b) {
                        printf("isosceles triangle!\n");
                    }
                    else if(b == c) {
                        printf("isosceles triangle!\n");
                    }
                    else {
                        printf("regular triangle!\n");
                    }
                }
                else {
                    printf("not a triangle!\n");
                }
            }
            else {
                printf("not a triangle!\n");
            }
        }
        else {
            printf("not a triangle!\n");
        }
    }
}