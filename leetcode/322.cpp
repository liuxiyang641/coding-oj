// https://leetcode.com/problems/coin-change/
// DP，完全背包问题，dp[i][j]：只考虑前i种硬币，满足总金额是j时的最小硬币数量

#include<algorithm>
using namespace std;

int minCoin(int x, int y) {
    // 需要特别判断x和y是-1的情况，y只有在不是-1的情况下，才可以+1然后与x进行比较
    if(x == -1) {
        if (y == -1) {
            return -1;
        }
        else {
            return y + 1;
        }
    }

    if(y == -1) {
        return x;
    }

    return x < (y + 1) ? x : (y + 1);
}

int coinChange(int* coins, int coinsSize, int amount){
    int** dp = (int**)malloc(sizeof(int*) * (coinsSize+1));
    for(int i = 0; i<=coinsSize; ++i) {
        dp[i] = (int*)malloc(sizeof(int) * (amount + 1));
        for(int j = 0; j <= amount; ++j) {
            dp[i][j] = -1;
        }
    }
    // 任何硬币组合，如果amount是0，那么不需要使用硬币即可
    for(int i = 0; i<=coinsSize; ++i) {
        dp[i][0] = 0;
    }

    for(int i = 1; i <= coinsSize; ++i) {
        for(int j = 1; j <= amount; ++j) {
            if(j < coins[i-1]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = minCoin(dp[i-1][j], dp[i][j - coins[i-1]]);
            }
        }
    }

    int ans = dp[coinsSize][amount];
    free(dp);
    return ans;
}