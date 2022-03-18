// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int maxProfit(int* prices, int pricesSize){
    int minPrice = 1<<30 - 1;
    int maxRes = 0;
    for(int i = 0; i < pricesSize; ++i) {
        maxRes = max(maxRes, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    return maxRes;
}