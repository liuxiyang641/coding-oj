// https://leetcode.com/problems/decode-ways/
// DP， 分割类型的dp题，特点是不再依赖于相邻位置，而是可能更加靠前满足分割条件的位置
// dp[i]表示加入第i个字符时候可能的数字->字母的方案数量，特别注意的是0，位置[i]的元素不同，dp[i]有不同的状态转移矩阵

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;


// 判断s1 s2是否能组成合适的字母
bool isAvail(char s1, char s2)
{
    if (s1 == '0')
    {
        return false;
    }
    if (s1 == '1')
    {
        return true;
    }
    if (s1 == '2' && s2 <= '6')
    {
        return true;
    }
    return false;
}

int numDecodings(char *s)
{
    if (s[0] == '0')
    {
        return 0;
    }
    int len = strlen(s);
    int *dp = (int *)malloc(sizeof(int) * (len + 1));
    for (int i = 0; i < len + 1; ++i)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= len; ++i)
    {
        // 注意下面，这里i表示处理的字符位置，对应到char数组上，要-1
        if (s[i - 1] != '0')
        {
            dp[i] += dp[i - 1];
            if (isAvail(s[i - 2], s[i - 1]))
            {
                dp[i] += dp[i - 2];
            }
        }
        else // 当前位是0，只有10，20才符合条件
        {
            if (isAvail(s[i - 2], s[i - 1]))
            {
                dp[i] += dp[i - 2];
            }
            else {
                return 0; // 如果无法满足10，或者20，整个字符串无法继续decode
            }
        }
    }

    int ans = dp[len];
    free(dp);
    return ans;
}