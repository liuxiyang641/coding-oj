// https://leetcode.com/problems/house-robber-ii/
// 环形抢劫房子，不能抢劫相邻房间。把环形的抢房子问题转化为两个一维直线的抢房子问题：第一个房子不抢劫，转化为从第二个房子开始到最后的抢房子问题；
// 第一个房子抢劫，转化为移除最后一个房子的抢房子问题

#include<stdio.h>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int sub_rob(int *nums, int size)
{
    int r = 0, nr = 0;
    for(int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
        int tmp = r;
        r = nr + nums[i];
        nr = max(nr, tmp);
    }
    int ans = max(r, nr);
    // printf("%d ", ans);
    return max(r, nr);
}

int rob(int* nums, int size)
{
    if(size == 0)
        return 0;
    else if(size == 1)
        return *nums;
    else
        return max(sub_rob(nums, size - 1), sub_rob(nums + 1, size - 1));
}