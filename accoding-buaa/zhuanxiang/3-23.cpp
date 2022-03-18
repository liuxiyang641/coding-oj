// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        a = a * 10;
        c = c * 100;
        d = d * 10;
        int caseCount = 0;
        for(int i1 = 0; i1 <= 9; ++i1) {
            for(int i2 = 0; i2 <= 9; ++i2) {
                for(int i4 = 0; i4 <= 9; ++i4) {
                    for(int i3 = 0; i3 <= 9; ++i3) {
                        if((a + i1) * (i2 * 10 + b) == (i3 * 1000 + c + d + i4)) {
                            printf("case%d: %d%d*%d%d=%d%d%d%d\n", ++caseCount, a / 10, i1, i2, b, i3, c / 100, d / 10, i4);
                        }
                    }
                }
            }
        }
        if(!caseCount) {
            printf("IMPOSSIBLE!\n");
        }
    }
}