// https://leetcode.com/problems/minimum-path-sum/
// DP编程题，把题目看做是一个有向图，寻找源点出发的最短路径dp[i][j]，dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j]

#include<algorithm>
using namespace std;

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int** dp = (int**)malloc(sizeof(int*) * gridSize);
    for(int i = 0; i < gridSize; ++i) {
        dp[i] = (int*)malloc(sizeof(int) * (*gridColSize));
    }
    dp[0][0] = grid[0][0];
    for (int i = 1; i < gridSize; i++)
    {
        dp[i][0] = grid[i][0] + dp[i-1][0];
    }
    for (int i = 1; i < *gridColSize; i++)
    {
        dp[0][i] = grid[0][i] + dp[0][i-1];
    }
    for (int i = 1; i < gridSize; i++)
    {
        for (int j = 1; j < *gridColSize; j++)
        {
            dp[i][j] = dp[i][j-1] < dp[i-1][j] ? dp[i][j-1] : dp[i-1][j];
            dp[i][j] += grid[i][j];
        }
        
    }
    // for (int i = 0; i < gridSize; i++)
    // {
    //     for (int j = 0; j < *gridColSize; j++)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    int minPath = dp[gridSize-1][*gridColSize-1];
    free(dp);
    return minPath;
}