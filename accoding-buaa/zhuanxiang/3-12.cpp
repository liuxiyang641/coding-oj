// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main() {
    int isSanHao;
    double GPA;
    int scores1[3], scores2[3];
    while(scanf("%d %lf", &isSanHao, &GPA)!=EOF) {
        double avgScore1 = 0;
        for(int i = 0; i < 3; ++i) {
            scanf("%d", &scores1[i]);
            avgScore1 += scores1[i];
        }
        avgScore1 /= 3;
        double avgScore2 = 0;
        for(int i = 0; i < 3; ++i) {
            scanf("%d", &scores2[i]);
            avgScore2 += scores2[i];
        }
        avgScore2 /= 3;
        if(isSanHao) {
            if(GPA < 3.5) {
                if(avgScore1 < 80 || avgScore2 < 80) {
                    printf("REJECTED\n");
                }
                else {
                    printf("APPROVED\n");
                }
            }
            else {
                printf("APPROVED\n");
            }
        }
        else {
            if(GPA < 3.6) {
                if(avgScore1 <= 85 || avgScore2 <= 85) {
                    printf("REJECTED\n");
                }
                else {
                    printf("APPROVED\n");
                }
            }
            else {
                printf("APPROVED\n");
            }
        }
    }
}