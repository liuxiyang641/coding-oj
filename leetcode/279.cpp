// https://leetcode.com/problems/perfect-squares/
// 分割类型的DP题目：dp[i] = min(all(dp[j] + dp[i-j]))，注意处理可以直接平方得到的i，并且j的取值只需要是[1, (i/2)]
// 根据书上的解释，还可以简化，不需要遍历所有的情况，只需要处理所有的两个平方情况即可，i-1^2, i-2^2, i-3^2即可

#include <algorithm>
using namespace std;

int numSquares(int n)
{
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    int INF = (1 << 30) - 1;
    for (int i = 0; i <= n; ++i)
    {
        dp[i] = INF;
    }
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (i * i <= n)
        {
            dp[i * i] = 1;
        }
        // dp[i*i] = 1;
        if (dp[i] != 1)
        {
            for (int j = 1; j <= (i / 2); ++j)
            {
                dp[i] = dp[i] < (dp[j] + dp[i - j]) ? dp[i] : (dp[j] + dp[i - j]);
            }
        }
    }
    int ans = dp[n];
    free(dp);
    return ans;
}