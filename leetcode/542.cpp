// https://leetcode.com/problems/01-matrix/
// DP，dp[i][j] = min(四个方向dp[i][j]+1)，因为必须保证前面的状态已经计算好，因此从左上到右下，再从右下到左上，扫描两次

#include <algorithm>
using namespace std;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int min(int x, int y) {
    return x < y ? x : y;
}

int **updateMatrix(int **mat, int matSize, int *matColSize, int *returnSize, int **returnColumnSizes)
{
    int **dp = (int **)malloc(sizeof(int *) * matSize);
    int INF = (1 << 30) - 100;
    for (int i = 0; i < matSize; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (*matColSize));
        for (int j = 0; j < (*matColSize); ++j)
        {
            dp[i][j] = INF;
        }
    }
    // 开始从下、右两个方向开始搜索
    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < (*matColSize); ++j)
        {
            if (mat[i][j] == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i - 1 >= 0)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            if (j - 1 >= 0)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
    }
    // 开始从上、左两个方向开始搜索
    for (int i = matSize - 1; i >= 0; --i)
    {
        for (int j = (*matColSize) - 1; j >= 0; --j)
        {
            if (mat[i][j] == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i + 1 < matSize)
            {
                dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
            }
            if (j + 1 < (*matColSize))
            {
                dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
        }
    }
    *returnSize = matSize;
    *returnColumnSizes = (int *)malloc(sizeof(int) * (matSize));
    for (int i = 0; i < (matSize); ++i)
    {
        (*returnColumnSizes)[i] = *matColSize;
    }
    return dp;
}