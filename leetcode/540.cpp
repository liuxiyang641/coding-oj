// https://leetcode.com/problems/single-element-in-a-sorted-array/
// 二分查找，数组中所有的元素都是一定出现两次，除了一个特殊元素只出现1次，找到这个特殊的元素
// 方法

#include<algorithm>
using namespace std;

int singleNonDuplicate(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] == nums[mid + 1]) {
            mid++;
        }
        else if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }
        int lenPre = mid - l + 1;
        int lenAfter = r - (mid + 1) + 1;
        // 如果lenAfter就表示当前mid相等的元素走到了尽头，此时一定是有三个元素，并且首元素是特殊元素
        if(lenAfter == 0) {
            break;
        }
        if(lenPre % 2 != 0) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return nums[l];
}