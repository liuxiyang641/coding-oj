// https://accoding.buaa.edu.cn/contest-ng/index.html#/715/problems
// 求矩阵是否重叠以及重叠的面积
// 可以通过令 x>=max(x1, x3) && x<=min(x2, x4)来判断是否重叠，同时计算出重叠部分x的范围
#include<stdio.h>
#include<stdlib.h>

int* calTri(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int* tri = (int*)malloc(sizeof(int) * 4);
    for(int i = 0; i < 4; ++i) {
        tri[i] = 0;
    }
    if(x3 >= x1 && x3 <= x2) {
        if(y3 >= y1 && y3 <= y2) {
            tri[0] = x3;
            tri[1] = y3;
            tri[2] = x2;
            tri[3] = y2;
        }
    }
    return tri;
}

int main() {
    int x[7], y[7];
    int n;
    scanf("%d", &n);
    while(n--) {
        for(int i = 1; i <= 6; ++i) {
            scanf("%d %d", &x[i], &y[i]);
        }
    }
}