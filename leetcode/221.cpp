// https://leetcode.com/problems/maximal-square/
// DP，

#include<algorithm>
using namespace std;

int min(int x, int y, int z) {
    int ans = x < y ? x : y;
    ans = ans < z ? ans : z;
    return ans;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int** dp = (int**)malloc(sizeof(int*) * matrixSize);
    for(int i=0;i<matrixSize;++i) {
        dp[i] = (int*)malloc(sizeof(int) * (*matrixColSize));
        // for(int j=0; j < *matrixColSize; ++j) {
        //     dp[i][j] = 0;
        // }
    }
    int maxSquare = 0;
    // 处理第一行
    for(int i=0; i < (*matrixColSize); i++) {
        if(matrix[0][i]=='0') {
            dp[0][i] = 0;
        }
        else {
            dp[0][i] = 1;
            maxSquare = 1;
        }
    }
    // 处理第一列
    for(int i=1; i < matrixSize; i++) {
        if(matrix[i][0]=='0') {
            dp[i][0] = 0;
        }
        else {
            dp[i][0] = 1;
            maxSquare = 1;
        }
    }
    for (int i = 1; i < matrixSize; i++)
    {
        for(int j = 1; j < *matrixColSize; ++j) {
            if (matrix[i][j] == '0')
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
            if (dp[i][j] > maxSquare)
            {
                maxSquare = dp[i][j];
            }
        }
    }
    // printf("%d ", maxSquare);
    
    free(dp);
    return maxSquare * maxSquare;
}