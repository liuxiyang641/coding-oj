// https://leetcode.com/problems/longest-increasing-subsequence/
// DP，经典题目，寻找最大递增序列，dp[i] = max(dp[j] + 1)，j<i并且是char[j] < char[i]

#include <algorithm>
using namespace std;

int max(int x, int y)
{
    return x > y ? x : y;
}

int lengthOfLIS(int *nums, int numsSize)
{
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        dp[i] = 1;
    }
    int maxLength = 1;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                maxLength = max(maxLength, dp[i]);
            }
        }
    }
    return maxLength;
}