#include<stdio.h>
#include<math.h>

int main() {
    int a[2010];
    int isEven[2010];
    int N;
    while(~scanf("%d", &N)) {
        for(int i = 1; i <= N; ++i) {
            scanf("%d", &a[i]);
            if(a[i] % 2 == 0) {
                isEven[i] = 1;
            }
        }
        for(int i = 1; i <= N; ++i) {
            for(int j = i + 1; j <= N; ++j) {
                if(isEven[i] == isEven[j] && abs(a[i] - a[j]) > 10) {
                    printf("%d %d\n", i, j);
                }
            }
        }
    }
}