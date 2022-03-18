// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>
#include<math.h>

int main() {
    for(int i = 2; i <= 1000; ++i) {
        int yinziSum = 1;
        double sq = sqrt(i);
        for(int j = 2; j <= sq; ++j) {
            if(i % j == 0) {
                if(i / j != j) {
                    yinziSum = yinziSum + j + (i / j);
                }
                else {
                    yinziSum = yinziSum + j;
                }
                if(yinziSum > i) {
                    break;
                }
            }
        }
        if(yinziSum == i) {
            printf("%d\n", i);
        }
    }
}