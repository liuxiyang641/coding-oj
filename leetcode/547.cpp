// https://leetcode.com/problems/number-of-provinces/
// 图上的DFS
#include<stdio.h>
#include<algorithm>

using namespace std;

void DFS(int i, bool isVis [], int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    // if (i < 0 || i >= isConnectedSize || j < 0 || j >= *isConnectedColSize || isConnected[i][j] == 0)
    //     return;
    // isConnected[i][j] = 0;
    isVis[i] = true; // 访问顶点i
    for(int j=0; j<(*isConnectedColSize); ++j) {
        // 访问邻居节点，并且防止重复的多次访问
        if (isConnected[i][j]==1 && isVis[j] == false) {
            DFS(j, isVis, isConnected, isConnectedSize, isConnectedColSize);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    int count = 0;
    bool *isVis = (bool*)malloc(isConnectedSize * sizeof(bool));
    for(int i=0;i<isConnectedSize;++i)
        isVis[i] = false;
    for(int i =0; i<isConnectedSize; ++i) {
        if(isVis[i]==false) {
            count++;
            DFS(i, isVis, isConnected, isConnectedSize, isConnectedColSize);
        }
    }
    free(isVis);
    return count;
}

int main() {
    int n;
    printf("22222\n");
    while(scanf("%d", &n)!=EOF) {
        printf("%d\n", n);
    }
    return 0;
}