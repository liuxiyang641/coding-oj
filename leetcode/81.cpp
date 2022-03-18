// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// 二分查找

#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool search(int* nums, int numsSize, int target){
    int l = 0, r=numsSize - 1;
    int mid;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if(nums[mid]==target) 
            return true;
        if (nums[mid]==nums[r])
        {
            --r;
        }    
        else if (nums[mid]>nums[r])
        {
            // l到mid是递增区间
            if (target>nums[mid])
            {
                l = mid + 1;
            }
            else
            {
                if (target>=nums[l])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        else
        {
            // mid到r是递增区间
            if (target>nums[mid])
            {
                if (target<=nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return false;
}

int main(int argc, char** argv)
{
    int * nums;
    int numsSize;
    int target;
    while(scanf("%d", &numsSize)!=EOF)
    {
        nums = (int *)malloc(numsSize * sizeof(int));
        for(int i = 0; i< numsSize;++i)
            scanf("%d", &nums[i]);
        scanf("%d", &target);
        printf(search(nums, numsSize, target) ? "true\n" : "false\n");
        free(nums);
    }
    return 0;
}