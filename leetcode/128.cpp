// https://leetcode.com/problems/longest-consecutive-sequence/
// 寻找乱序的序列中的最长连续子序列长度
// 思路是使用快排排好序，然后寻找最长连续的序列即可，注意要跳过前后相同值

#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int tmpLen = 1;
        for(int i = 1; i < nums.size();) {
            if(nums[i] == nums[i - 1]) {
                ++i;
            }
            else if(nums[i] == nums[i - 1] + 1) {
                tmpLen++;
                ++i;
                maxLen = maxLen > tmpLen ? maxLen : tmpLen;
            }
            else {
                ++i;
                tmpLen = 1;
            }
        }
        return maxLen;
    }
};