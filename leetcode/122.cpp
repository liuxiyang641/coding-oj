// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// 贪心算法，股票问题

#include<algorithm>
using namespace std;

int maxProfit(int* prices, int pricesSize) {
    int ans = 0;
    // 开始贪心算法，
    int i = 0;
    while(i < pricesSize) {
        // 如果princes[i]比后面的prices大，那么以后面的prices买入肯定获利更多
        while(i + 1 < pricesSize && prices[i] > prices[i + 1]) {
            i++;
        }
        int buy = i;
        // 如果princes[i]比后面的prices小，那么以后面的prices卖出肯定获利更多
        while(i + 1 < pricesSize && prices[i] < prices[i + 1]) {
            i++;
        }
        int sell = i;
        ans += (prices[sell] - prices[buy]);
        ++i;
    }
    return ans;
}