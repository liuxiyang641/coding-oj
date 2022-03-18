// https://leetcode.com/problems/two-sum/
// 求解数组中哪两个数相加是等于target的

#include<vector>
#include<algorithm>
#include<map>
using namespace std;

// 第一个最简单的方法，O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < nums.size(); ++j) {
                if(i != j && nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

// 第二种解法，使用hash办法，利用unordered_map来储存
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> keyPos;
        int key;
        for(int i = 0; i < nums.size(); ++i) {
            key = target - nums[i];
            unordered_map<int, int>::iterator it = keyPos.find(key);
                if(it != keyPos.end()) {
                    ans.push_back(it->second);
                    ans.push_back(i);
                    return ans;
                }
            keyPos[nums[i]] = i;
        }
        return ans;
    }
};