// https://leetcode.com/problems/count-binary-substrings/
// 统计字符串当中01子串

#include<string.h>
#include<algorithm>
using namespace std;


int countBinarySubstrings(char * s) {
    int ans = 0;
    int len = strlen(s);
    int i = 1;
    while(i < len) {
        if(s[i] != s[i-1]) {
            int j = 0;
            for(; i - 1 - j >= 0 && i + j < len; ++j) {
                // 如果以s[i]和s[i-1]往两端走可以继续匹配
                if(s[i] == s[i + j] && s[i - 1] == s[i - 1 - j]) {
                    ans++;
                }
                else {
                    break;
                }
            }
            i = i + j;
        }
        else {
            i++;
        }
    }
    return ans;
}