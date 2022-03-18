// https://leetcode.com/problems/maximum-subarray/

#include<stdio.h>
#include<stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxSubArray(int* nums, int numsSize){
    int* dp = (int*)malloc(sizeof(int) * (numsSize + 1));
    dp[1] = nums[0];
    int ansMax = dp[1];
    for(int i = 2; i <= numsSize; ++i) {
        // printf("%d ", dp[i]);
        dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
        ansMax = max(ansMax, dp[i]);
    }
    return ansMax;
}

int main() {
    int a;
    while(scanf("%d", &a)!=EOF) {
        a = a + 1;
        printf("%d\n", a);
    }
    return 0;
}