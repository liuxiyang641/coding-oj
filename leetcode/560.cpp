// https://leetcode.com/problems/subarray-sum-equals-k/

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int ans = 0;
        vector<int> arraySum(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            arraySum[i] = sum;
            sum += nums[i];
            for(int j = 0; j <= i; ++j) {
                if(arraySum[i] - arraySum[j] + nums[i] == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
// 分析上面的解法可以发现，arraySum[j] == arraySum[i] - k + nums[i]，实际是一个固定值，因此只需要统计合适的前缀和有几个即可
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> arraySum;
        arraySum[0] = 1;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ans += arraySum[sum - k]; // 有多少个前缀和等于sum - k
            ++arraySum[sum];
        }
        return ans;
    }
};