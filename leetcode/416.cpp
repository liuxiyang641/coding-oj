// https://leetcode.com/problems/partition-equal-subset-sum/
// DP，01背包问题，计算不同子集和能否满足特定值，dp[i][j]表示考虑前i个元素，能否满足子集和是j

#include<algorithm>
using namespace std;

bool canPartition(int *nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
    }
    if(sum % 2) {
        return false;
    }
    // 希望部分数组和能够达到sum/2
    sum = sum / 2;
    bool** dp = (bool**)malloc(sizeof(bool*) * (numsSize + 1));
    for (int i = 0; i <= numsSize; ++i) {
        dp[i] = (bool*)malloc(sizeof(bool) * (sum + 1));
        for (int j = 0; j <= sum; ++j) {
            dp[i][j] = false; // false表示考虑第i个数字的时候，不能凑满j
        }
    }
    
    // 使用dp[0][]表示第0件物品，除了dp[0][0]外都应该设置为false
    // dp[0][0] = true;
    for(int i = 0; i <= numsSize; ++i) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= numsSize; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (j < nums[i-1]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                // 考虑两种情况，加入nums[i]和不加入nums[i]，只要这两种情况有任意一个能够凑满j，dp[i][j]就可以为true
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
        }
    }
    bool res = dp[numsSize][sum];
    free(dp);
    return res;
}