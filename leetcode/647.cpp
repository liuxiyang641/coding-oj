// https://leetcode.com/problems/palindromic-substrings/
// 统计字符串中的回文子串的数量


#include<algorithm>
#include<string.h>
using namespace std;

typedef struct {
    int length[1001]; // 以当前位置结尾的回文子串
    int size;
} node;

int countSubstrings(char * s) {
    int len = strlen(s);
    int ans = len;
    node* palindroms = (node*)malloc(sizeof(node) * len);
    // 初始化以i结尾的回文长度，包括0和1
    for(int i = 0; i < len; ++i) {
        palindroms[i].size = 2;
        palindroms[i].length[0] = 0;
        palindroms[i].length[1] = 1;
    }
    for(int i = 1; i < len; ++i) {
        for(int j = 0; j < palindroms[i - 1].size; ++j) {
            // 需要和s[i]对比的位置
            int preAlignPos = i - 1 - palindroms[i - 1].length[j];
            // 统计新的回文子串数量
            if(preAlignPos >= 0 && s[preAlignPos] == s[i]) {
                palindroms[i].length[palindroms[i].size++] = palindroms[i - 1].length[j] + 2;
                ans++;
            }
        }
    }
    return ans;
}