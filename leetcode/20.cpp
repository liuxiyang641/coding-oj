// https://leetcode.com/problems/valid-parentheses/
// 判断全是括号的字符串是否合法，使用栈来进行匹配即可

#include<string>
#include<stack>
using namespace std;

class Solution {
private:
    stack<char> sta;
public:
    bool isValid(string s) {
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                sta.push(s[i]);
            }
            else {
                if(sta.empty()) {
                    return false;
                }
                switch (s[i])
                {
                case ')':
                    if(sta.top() == '(') {
                        sta.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                case '}':
                    if(sta.top() == '{') {
                        sta.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                case ']':
                    if(sta.top() == '[') {
                        sta.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                default:
                    return false;
                }
            }
        }
        return sta.empty();
    }
};