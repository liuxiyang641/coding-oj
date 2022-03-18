// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// DP，股票问题，涉及到了多个状态，包括是否买入，是否卖出，是否处于买入->卖出，是否处于卖出->买入阶段

#include <algorithm>
using namespace std;

// 下面的解法是自己想的，会超时
int min(int x, int y) {
    return x < y ? x : y;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int maxProfit(int* prices, int pricesSize){
    int* dp = (int*)malloc(sizeof(int) * (pricesSize + 1));
    dp[0] = 0;
    int maxPro = 0;
    for(int i = 1 ; i <= pricesSize; ++i) {
        dp[i] = 0;
        // 如果前面j天都不sell股票
        for (int j = 0; j < i - 1; ++j) {
            dp[i] = max(dp[i], prices[i - 1] - prices[j]);
        }
        // 如果前面j天有一天sell股票
        for (int j = 2; j <= i - 3; ++j) {
            for (int k = j + 2; k <= i - 1; ++k) {
                dp[i] = max(dp[i], dp[j] + (prices[i - 1] - prices[k - 1]));
            }
        }
        // printf("%d ", dp[i]);
        maxPro = max(maxPro, dp[i]);
    }
    free(dp);
    return maxPro;
}

// 下面的解法是书上的解法，设置了多个dp数组对应i天的不同状态，这些状态之间相互转化，最后输出最大值即可
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
    {
        return 0;
    }
    vector<int> buy(n), sell(n), s1(n), s2(n);
    s1[0] = buy[0] = -prices[0];
    sell[0] = s2[0] = 0;

    for (int i = 1; i < n; i++)
    {
        buy[i] = s2[i - 1] - prices[i];
        s1[i] = max(buy[i - 1], s1[i - 1]);
        sell[i] = max(buy[i - 1], s1[i - 1]) + prices[i];
        s2[i] = max(s2[i - 1], sell[i - 1]);
    }

    return max(sell[n - 1], s2[n - 1]);
}