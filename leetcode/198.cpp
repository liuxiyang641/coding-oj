// https://leetcode.com/problems/house-robber/
// 同样是动态规划，dp[i]表示抢劫到i个house时候的最大财富，dp[i] = max(dp[i-1], dp[i-2] + nums[i])，做的时候要注意边界的处理

#include<algorithm>
#include<math.h>
using namespace std;

int DP(int* nums, int numsSize, int* dp) {
    dp[1] = nums[0];
    for(int i = 2; i <= numsSize; ++i) {
        dp[i] = dp[i-1] > (dp[i-2] + nums[i-1]) ? dp[i-1] : (dp[i-2] + nums[i-1]);
    }
    return dp[numsSize];
}

int rob(int* nums, int numsSize){
    int* dp = (int*)malloc(sizeof(int) * (numsSize + 1));
    for(int i=0;i<numsSize+1;++i) {
        dp[i] = 0;
    }
    int ans = DP(nums, numsSize, dp);
    free(dp);
    return ans;
}