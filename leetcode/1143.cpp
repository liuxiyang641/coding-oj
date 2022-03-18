// https://leetcode.com/problems/longest-common-subsequence/
// DP，经典题目，寻找两个字符的最大匹配子序列，dp[i][j]表示第一个字符串位置i，第二个字符串位置j的最大匹配长度

#include <algorithm>
#include <string.h>
using namespace std;

int longestCommonSubsequence(char *text1, char *text2)
{
    int len1 = strlen(text1), len2 = strlen(text2);
    int **dp = (int **)malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i < len1 + 1; ++i)
    {
        dp[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        for(int j = 0; j < len2 + 1; ++j) {
            dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= len1; ++i) {
        for(int j = 1; j <= len2; ++j) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    // 如果是取text1[0-i-1]和text2[0-j]，那么text1[i]就没有参加统计
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    // 如果是text2[j]不需要参加统计
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    int maxLength = dp[len1][len2];
    free(dp);
    return maxLength;
}