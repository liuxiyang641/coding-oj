// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// 贪心算法，计算最少能够覆盖所有线段的区间数量

#include<algorithm>
using namespace std;

// 注意这里的写法，不直接相减两个int值结果避免超出界限，而是比较返回值
int cmp(const void* a, const void* b) {
    // printf("%d ", (*((int**)a))[1]);
    int tmpa = (*((int**)a))[1];
    int tmpb = (*((int**)b))[1];
    if(tmpa < tmpb) {
        return -1;
    }
    else if(tmpa > tmpb) {
        return 1;
    }
    else {
        return 0;
    }
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    qsort(points, pointsSize, sizeof(int*), cmp);
    int ans = 1;
    int preRight = points[0][1];
    // 贪心算法，对于前面的一个线段，至少会有一颗子弹瞄准这个线段区间，然后尝试能否同时瞄准更多的后续线段
    for(int i = 1; i < pointsSize; ++i) {
        if(points[i][0] <= preRight) {
            continue;
        }
        else {
            ans++;
            preRight = points[i][1];
        }
    }
    return ans;
}