// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// 自己实现的lower_bound和upper_bound，使用二分查找即可

#include <stdio.h>
#include <stdlib.h>
using namespace std;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    if (numsSize==0)
    {
        int * ret = (int *)malloc(2 * sizeof(int));
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    if (numsSize==1)
    {
        int * ret = (int *)malloc(2 * sizeof(int));
        ret[0] = -1;
        ret[1] = -1;
        if (nums[0]==target)
        {
            ret[0] = 0;
            ret[1] = 0;
        }
        return ret;
    }
    int mid;
    int upper_bound=-1, lower_bound = -1;
    int l = 0, r = numsSize - 1;
    bool flag = false;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if (nums[mid]<target)
        {
            l = mid + 1;
        }
        else if (nums[mid]>target)
        {
            r = mid - 1;
        }
        else
        {
            // 如果相等，下边界一定在l和mid之间。
            flag = true;
            r = mid - 1;
        }
    }
    if (flag)
        lower_bound = r+1;
    else
    {
        int * ret = (int *)malloc(2 * sizeof(int));
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    
    l = 0, r = numsSize - 1;
    // search upper bound
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if (nums[mid]<target)
        {
            l = mid + 1;
        }
        else if (nums[mid]>target)
        {
            r = mid - 1;
        }
        else
        {
            // 如果相等，上边界一定在mid和r之间。
            l = mid + 1;
        }
    }
     if (nums[l - 1]==target)
        upper_bound = l - 1;
    
    int * ret = (int *)malloc(2 * sizeof(int));
    ret[0] = lower_bound;
    ret[1] = upper_bound;
    return ret;
}

int main(int argc, char** argv)
{
    int input;
    while(scanf(""))
    {
        
    }
}