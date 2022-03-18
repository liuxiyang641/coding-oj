// https://leetcode.com/problems/ones-and-zeroes/
// DP，01背包问题，多维费用的01背包，需要考虑两种限制条件

#include<algorithm>
#include<string.h>
using namespace std;

int max(int x, int y) {
    return x > y ? x: y;
}

int findMaxForm(char ** strs, int strsSize, int m, int n){
    int* zeroCount = (int*)malloc(sizeof(int) * strsSize);
    int* oneCount = (int*)malloc(sizeof(int) * strsSize);

    for(int i = 0; i < strsSize; ++i) {
        int strLen = strlen(strs[i]);
        zeroCount[i] = oneCount[i] = 0;
        for(int j = 0; j < strLen; ++j) {
            if (strs[i][j] == '0') {
                zeroCount[i]++;
            }
            else {
                oneCount[i]++;
            }
        }
    }

    int*** dp = (int***)malloc(sizeof(int**) * (strsSize + 1));
    for(int i = 0; i <= strsSize; ++i) {
        dp[i] = (int**)malloc(sizeof(int*) * (m + 1));
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = (int*)malloc(sizeof(int) * (n + 1));
            for (int k = 0; k <= n; ++k) {
                dp[i][j][k] = 0;
            }
        }
    }

    for(int i = 1; i <= strsSize; ++i) {
        // 这里注意考虑，需要加入j=0和k=0的情况
        for(int j = 0; j <= m; ++j) {
            for(int k = 0; k <= n; ++k) {
                if (zeroCount[i - 1] > j || oneCount[i - 1] > k) {
                    dp[i][j][k] = dp[i-1][j][k];
                }
                else {
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-zeroCount[i-1]][k-oneCount[i-1]] + 1);
                }
            }
        }
    }

    int ans = dp[strsSize][m][n];
    free(dp);
    return ans;
}