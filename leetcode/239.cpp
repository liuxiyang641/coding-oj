// https://leetcode.com/problems/sliding-window-maximum/
// 通过维护一个双端队列，保存一个窗口内最大值的位置，新加入的元素nums[i]加入到队列右边，遇到小于它的元素就把该元素弹出去，直到找到比新元素大的元素
// 或者为空，再放入新元素位置i。如果队列左边的最大元素是超出了边界，就弹出，再保存队列边界左边的最大值。

#include <algorithm>
#include <queue>
using namespace std;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            {
                if (!dq.empty() && dq.front() == i - k)
                {
                    dq.pop_front();
                }
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};