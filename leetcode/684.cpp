// https://leetcode.com/problems/redundant-connection/


#include<algorithm>
using namespace std;

int find(int i, int* parent) {
    while(parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void unionSet(int x, int y, int* parent) {
    int parentX = find(x, parent);
    int parentY = find(y, parent);
    parent[parentY] = parentX;
    // 缩短并查集路径，直接把并查集的父结点改为最根本的父结点
    while(parent[x] != parentX) {
        int tmp = parent[x];
        parent[x] = parentX;
        x = tmp;
    }
    while(parent[y] != parentX) {
        int tmp = parent[y];
        parent[y] = parentX;
        y = tmp;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int* parent = (int*)malloc(sizeof(int) * 1001);
    int* ans = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for(int i = 0; i < 1001; ++i) {
        parent[i] = i;
    }
    for(int i = 0; i < edgesSize; ++i) {
        int a = edges[i][0];
        int b = edges[i][1];
        if(find(a, parent) != find(b, parent)) {
            unionSet(a, b, parent);
        }
        else {
            ans[0] = a;
            ans[1] = b;
            return ans;
        }
    }
    free(parent);
    return ans;
}