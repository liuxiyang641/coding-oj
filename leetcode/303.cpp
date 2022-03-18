// https://leetcode.com/problems/range-sum-query-immutable/
// 求前缀和

#include<vector>
using namespace std;

class NumArray {
private:
    vector<long long> arraySum;
    vector<int> arrayNum;
public:
    NumArray(vector<int>& nums) {
        arraySum.push_back(nums[0]);
        arrayNum.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i) {
            arraySum.push_back(arraySum[i - 1] + nums[i]);
            arrayNum.push_back(nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        // cout<<arraySum[right]<<" ";
        return arraySum[right] - arraySum[left] + arrayNum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */