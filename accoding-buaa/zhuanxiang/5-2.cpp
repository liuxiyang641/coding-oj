#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int temple[1001];
    int inBag[1001];
    int saveIntoBag[1001];
    int m, n;
    while(scanf("%d %d", &m, &n)!=EOF) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &temple[i]);
        }
        memset(inBag, 0, sizeof(inBag));
        memset(saveIntoBag, 0, sizeof(saveIntoBag));
        int leftSpace = m;
        int returnCount = 0;
        int first = 0;
        for(int i = 1; i <= n; ++i) {
            // 开始走神庙
            if(!inBag[temple[i]]) {
                // 如果所需要的素材不在背包里
                if(leftSpace > 0) {
                    returnCount++;
                    inBag[temple[i]] = 1;
                    saveIntoBag[i] = 1; // 记录在这一步放入了素材
                    leftSpace--;
                }
                else {
                    returnCount++;
                    // 取出最早的素材
                    for(int j = first; j <= i; ++j) {
                        if(saveIntoBag[j]) {
                            inBag[temple[j]] = 0; // 取出素材
                            inBag[temple[i]] = 1; // 放入新素材
                            saveIntoBag[i] = 1;
                            first = j + 1;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n", returnCount);
    }
}