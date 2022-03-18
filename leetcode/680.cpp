// https://leetcode.com/problems/valid-palindrome-ii/
// 双指针，判断一个字符串在最多删除一个字符的情况下，能否变为回文字符串

#include<algorithm>
#include<string.h>
using namespace std;

bool checkPalindrome(char * s, int l, int r, bool haveDelete) {
    while(l < r) {
        if(s[l] != s[r]) {
            if(haveDelete) {
                return false;
            }
            else {
                if(checkPalindrome(s, l + 1, r, true)) {
                    return true;
                }
                else if(checkPalindrome(s, l, r - 1, true)){
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        else {
            l++;
            r--;
        }
    }
    return true;
}

bool validPalindrome(char * s) {
    return checkPalindrome(s, 0, strlen(s) - 1, false);
}