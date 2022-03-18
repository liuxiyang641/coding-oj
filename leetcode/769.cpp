// https://leetcode.com/problems/max-chunks-to-make-sorted/
// 对于随机排列，检查是否能够分成多个分别排序好后，不需要再集合起来归并排序的区间
// 核心是注意到是元素各不相同的排列，只需要找到了最大值和最小值就可以划分出去
// LeetCode书上有更简单直接的解法，只需要判断什么时候数组最大值==位置i即可，满足这一点时，i左边的所有i-1个元素各不相同且都小于i，那么所有小于i的元素一定都已经在左边了

#include<vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size() == 1) {
            return 1;
        }

        int maxChunks = 0;

        bool findMinChunkVal = false;
        int maxChunkVal = -1, minChunkVal = 0;

        for(int i = 0; i < arr.size(); ++i) {
            // 记录当前chunk的最大值
            if(arr[i] > maxChunkVal) {
                maxChunkVal = arr[i];
            }
            // 记录是否找到了应该存在的当前chunk的最小值
            if(arr[i] == minChunkVal) {
                findMinChunkVal = true;
            }
            // 如果已经同时找到了当前chunk的最小值和最大值i，那么就可以直接划分出去
            if(findMinChunkVal && maxChunkVal == i) {
                maxChunks++;
                minChunkVal = i + 1;
            }
        }
        return maxChunks;
    }
};