// https://leetcode.com/problems/edit-distance/
// DP，字符串编辑问题，涉及到两个字符串，同时需要考虑当前状态的变化

#include <string>
#include <vector>
using namespace std;

int minDistance(string word1, string word2)
{
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0) // 需要增加j个字符
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i; // 需要删除i个字符
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1] + ((word1[i - 1] == word2[j - 1]) ? 0 : 1),
                               min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            }
        }
    }
    return dp[m][n];
}