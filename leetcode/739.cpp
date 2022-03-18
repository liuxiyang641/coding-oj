// https://leetcode.com/problems/daily-temperatures/
// 使用栈来保存当前还不知道经过多少天更热的天气i，如果遇上更热的天气，就可以不断出栈，直至无法出栈

#include<vector>
#include<stack>
using namespace std;

class Solution {
private:
    stack<int> unknownDay;
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> warmerDay;
        unknownDay.push(0);
        warmerDay.push_back(0);
        for(int i = 1; i < temperatures.size(); ++i) {
            // 只要当前天比以前未知哪一天更热的气温更高，就可以直接计算出要经过多少天
            while(!unknownDay.empty() && temperatures[i] > temperatures[unknownDay.top()]) {
                warmerDay[unknownDay.top()] = i - unknownDay.top();
                unknownDay.pop();
            }
            unknownDay.push(i);
            warmerDay.push_back(0);
        }
        return warmerDay;
    }
};