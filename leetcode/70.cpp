// https://leetcode.com/problems/climbing-stairs/
// 动态规划，dp[i]表示走i有几步，需要注意的是边界值设置。本质是斐波那契数列

#include<algorithm>
using namespace std;

// 下面是递归的写法
int DP(int n, int* dp) {
    if(n < 0) {
        return 0;
    }
    if(dp[n]==0) {
        dp[n] = DP(n-1, dp) + DP(n-2, dp);
    }
    return dp[n];
}

// 根据书上的内容，有跟简介的写法，不需要从n->1的递归，而是直接从2->n，循环计算即可。同时还不需要记录全部的dp，只需要不断更新前两步即可
int DP2(int n) {
    int pre1 = 1, pre2 = 1;
    int cur;
    for(int i = 2; i <= n; ++i) {
        cur = pre1 + pre2;
        pre1 = pre2;
        pre2 = cur;
    }
    return pre2;
}

int climbStairs(int n){
    int* dp = (int*)malloc(sizeof(int) * (n+1));
    for(int i=0;i<n+1;++i) {
        dp[i] = 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    // int ans = DP(n, dp);
    int ans = DP2(n);
    free(dp);
    return ans;
}