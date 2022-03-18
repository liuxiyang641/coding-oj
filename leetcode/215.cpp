//  Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// 使用快排
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// 该函数返回当前选择的最左边的值，应该在数组中处于的位置p，左边的数字比p大，右边的数字比p小
int quickSelection(int* nums, int l, int r)
{
    if (l==r) return l;
    // 随机挑选一个值，并且与最左边的值互换，避免最糟糕的情况
    srand(0);
    int rand_init_pos = rand() % (r - l) + l;
    int tmp = nums[l];
    nums[l] = nums[rand_init_pos];
    nums[rand_init_pos] = tmp;

    int p_value = nums[l];
    int i = l, j=r;
    while(i<j)
    {
        while(i<j && nums[j]<=p_value)
        {
            j--;
        }
        // 将找到的大于p value的数从右边移到左边
        nums[i] = nums[j];
        while(i<j && nums[i]>=p_value)
        {
            i++;
        }
        // 将找到的小于p value的数从左边移到右边
        nums[j] = nums[i];
    }
    // 最后找到的i=j就是p_value的方向
    nums[i] = p_value;
    return i;
}

int findKthLargest(int* nums, int numsSize, int k)
{
    int l = 0, r=numsSize - 1;
    k = k-1;
    int p;
    while(l<=r)
    {
        p = quickSelection(nums, l, r);
        if (p == k)
        {
            return nums[p];
        }
        else if (p<k)
        {
            l = p + 1;
        }
        else
        {
            r = p - 1;
        }
    }
    return 0;
}