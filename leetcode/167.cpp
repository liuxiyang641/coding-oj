// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// 双指针，从数组左右两边出发，在一个排好序的数组中，寻找两个元素，使其和等于目标

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start_id = 0, end_id = numbers.size() - 1;
        while(true)
        {
            int ideal_value = target - numbers[start_id];
            if (numbers[end_id] == ideal_value)
            {
                break;
            }
            else if (numbers[end_id] < ideal_value)
            {
                start_id++;
            }
            else
            {
                end_id--;
            }
        }
        return vector<int> {start_id+1, end_id+1};
    }
};

int main(int argc, char** argv)
{
    while(true)
    {
        int input;
        vector<int> numbers;
        while (cin>>input)
        {
            numbers.push_back(input);
            if(cin.get()=='\n') break;
        }
        int target;
        cin>>target;
        Solution solution;
        vector<int> out = solution.twoSum(numbers, target);
        cout<<out[0]<<' '<<out[1]<<endl;
    }
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    if(numbersSize <= 1) {
        return ans;
    }
    int i1 = 0, i2 = numbersSize - 1;
    while(i1 < i2) {
        if(numbers[i1] + numbers[i2] == target) {
            ans[0] = i1 + 1;
            ans[1] = i2 + 1;
            return ans;
        }
        else if(numbers[i1] + numbers[i2] > target) {
            i2--;
        }
        else {
            i1++;
        }
    }
    return ans;
}