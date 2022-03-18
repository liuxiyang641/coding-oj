// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main() {
    int m;
    while(scanf("%d", &m)!=EOF) {
        int subSum = 0;
        for(int i = 2; i <= m; ++i) {
            int j = 1;
            for(; j <= m; ++j) {
                subSum = (j + (j + i - 1)) * i / 2;
                if(subSum == m) {
                    break;
                }
                else if(subSum > m) {
                    break;
                }
            }
            if(subSum == m) {
                printf("%d = %d", m, j);
                for(int z = 2; z <= i; ++z) {
                    printf(" + %d", j + z - 1);
                }
                printf("\n");
                break;
            }
            
        }
        if(subSum != m) {
            printf("-1\n");
        }
    }
}