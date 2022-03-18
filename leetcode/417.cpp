// https://leetcode.com/problems/pacific-atlantic-water-flow/
// DFS图，这道题可以学习到的知识在于，图上的DFS必须将已经访问过的顶点排除，并且在DFS过程中根结点以外的其它节点，在重新作为根结点进行DFS时有不同的性质
// 这道题另外的启发是，DFS合理的选择根结点，会大大减小运算难度
#include<stdio.h>
#include<algorithm>
using namespace std;

int dirI [4]= {-1, 1, 0, 0};
int dirJ [4]= {0, 0, -1, 1};

int DFS(int i, int j, int** heights, int** visited, int heightsSize, int* heightsColSize, int preHeight) {
    if(i<0 || j<0)
        return 1;
    if(i>=heightsSize || j >= (*heightsColSize))
        return 2;
    if(heights[i][j] > preHeight) {
        return -1; // 当前节点高度已经高于上一步节点高度，不能到达当前节点
    }
    // 可以到达当前节点的情况：
    if(i == 0 && j == (*heightsColSize) - 1){ // 山脉右上角
        visited[i][j] = 3; // 1表示可以满足题目要求
        return 3;
    }
    if(i == heightsSize - 1 && j == 0) { // 山脉左下角
        visited[i][j] = 3;
        return 3;
    }
    if(visited[i][j]!=0) // 当前节点已经知道是什么情况，直接返回
        return visited[i][j];
    
    // 接下来是还未知当前节点是否可以走得通的情况，需要继续遍历邻居
    visited[i][j] = -1; // 已经走过的不应该继续走
    bool toAtl = false, toPac = false;
    int tmp;
    for(int dir = 0; dir < 4; ++dir) {
        tmp = DFS(i + dirI[dir], j + dirJ[dir], heights, visited, heightsSize, heightsColSize, heights[i][j]);
        if (tmp == 1) {
            toPac = true;
        }
        else if (tmp == 2){
            toAtl = true;
        }
        else if (tmp == 3) {
            toPac = toAtl = true;
        }
    }
    if(toAtl==true && toPac==true) {
        tmp = 3;
        visited[i][j] = 3;
    }
    else if (toAtl==true) {
        tmp = 2;
        visited[i][j] = 0;
    }
    else if (toPac==true) {
        tmp = 1;
        visited[i][j] = 0;
    }
    else { // 其它情况
        tmp = -1;
        visited[i][j] = 0;
    }
     // 对于i，j根结点除外的其它被遍历的节点，实际还未知到底能否成功
    return tmp;
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes){
    int** results = (int **)malloc(sizeof(int *) * heightsSize * (*heightsColSize));
    int** visited = (int **)malloc(heightsSize * sizeof(int *));
    for(int i =0; i < heightsSize; ++i) {
        visited[i] = (int *)malloc((*heightsColSize) * sizeof(int));
        for(int j = 0; j<(*heightsColSize); ++j) {
            visited[i][j] = 0; // 0表示还未访问过
        }
    }
    // returnSize = (int *)malloc(sizeof(int));
    *returnSize = 0;
    
    for(int i =0; i < heightsSize; ++i) {
        for(int j = 0; j<(*heightsColSize); ++j) {
            int res = DFS(i, j, heights, visited, heightsSize, heightsColSize, heights[i][j]);
            visited[i][j] = res; // 只有根结点已经肯定是否能够通过DFS满足题目
            if(res == 3) {
                results[*returnSize] =  (int *)malloc(sizeof(int) * 2);
                results[*returnSize][0] = i;
                results[*returnSize][1] = j;
                (*returnSize) = (*returnSize) + 1;
            }
        }
    }
    
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++){
        (*returnColumnSizes)[i] = 2;
    }

    return results;
}