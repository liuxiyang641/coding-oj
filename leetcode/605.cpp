// https://leetcode.com/problems/can-place-flowers/
// 贪心算法，满足两边邻居不都是1的点的数量，从左到右和从右到左扫描即可

#include<algorithm>
#include<string.h>
using namespace std;

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int* canPlace = (int*)malloc(sizeof(int) * flowerbedSize);
    // 记住memset的用法，是memset(array, value, sizeof array)，最后的size是整个数组的size
    memset(canPlace, 0, sizeof(int)*flowerbedSize);
    if(flowerbed[0] != 1) {
        canPlace[0] = 1;
    }
    // 从左到右遍历，寻找满足左边邻居不是1的最多点的数量
    for(int i = 1; i < flowerbedSize; ++i) {
        if(flowerbed[i] != 1) {
            if(flowerbed[i - 1] == 0) {
                // 只有当前位置不是1，前一个位置不是1，并且前一个位置没有尝试存放新的1，才能在当前位置放新的1
                if(canPlace[i - 1] == 0) {
                    canPlace[i] = 1;
                }
            }
        }
    }
    // 从右到左遍历，去除所有右边邻居是1的点
    for(int i = flowerbedSize - 2; i >= 0; --i) {
        if(flowerbed[i + 1] == 1) {
            canPlace[i] = 0;
        }
    }
    int ans = 0;
    // 统计最终结果
    for(int i = 0; i < flowerbedSize; ++i) {
        // printf("%d ", canPlace[i]);
        ans += canPlace[i];
    }
    if(ans >= n) {
        return true;
    }
    else {
        return false;
    }
}