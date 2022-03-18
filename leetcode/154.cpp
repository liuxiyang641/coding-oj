// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// 旋转数组寻找最小值，二分查找，最麻烦的是会出现重复元素，很容易出现死循环的问题，解决方法是保证左右指针元素不相等

#include<algorithm>
using namespace std;

int findMin(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    int mid;
    while(l < r) {
        if(nums[l] < nums[r]) {
            break;
        }
        if(nums[l] == nums[r]) {
            l++;
            continue;
        }
        mid = l + (r - l) / 2;
        if(nums[mid] < nums[l]) {
            r = mid;
        }
        else if(nums[mid] > nums[l]) {
            l = mid;
        }
        else {
            // 去除所有重复的mid
            // 防止相同元素数组，出现死循环
            bool firstLoop = false;
            while(mid < r && nums[mid] == nums[l]) {
                mid = (mid + 1);
            }
            l = mid;
        }
    }
    return nums[l];
}