// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// 查询某个元素是否在已经输入的数组中存在，根据LeetCode上的写法，更简单的写法是直接在原数组上设置出现过的数字的位置为负数即可

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        bool isAppeared[100010];
        fill(isAppeared, isAppeared + 100010, false);
        vector<int> ans;
        for(int i = 1; i <= nums.size(); ++i) {
            isAppeared[nums[i - 1]] = true;
        }
        for(int i = 1; i <= nums.size(); ++i) {
            if(!isAppeared[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};