// https://leetcode.com/problems/top-k-frequent-elements/
// 寻找数组中TOP k频繁出现的元素
// 注意，在c语言环境下，无法直接使用map统计不同元素出现次数，可以通过先排序数组，然后利用一个二维数组统计出现技术的方式，最后排序即可

#include<algorithm>
using namespace std;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp1(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}

int cmp2(const void* a, const void* b) {
    int* tmpa = *((int**)a), *tmpb = *((int**)b);
    // printf("%d %d\n", (*((int**)a))[1], (*((int**)b))[1]);
    return tmpb[1] - tmpa[1];
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp1);
    // for(int i = 0; i < numsSize; ++i) {
    //     printf("%d\n", nums[i]);
    // }
    // 出现的不同元素和出现次数
    int** freqCount = (int**)malloc(sizeof(int*) * 100000);
    int diffCount = 1;
    freqCount[0] = (int*)malloc(sizeof(int) * 2);
    freqCount[0][0] = nums[0];
    freqCount[0][1] = 1;
    for(int i = 1; i < numsSize; ++i) {
        if(nums[i] == nums[i - 1]) {
            freqCount[diffCount - 1][1]++;
        }
        else {
            // 出现新的数字
            diffCount++;
            freqCount[diffCount - 1] = (int*)malloc(sizeof(int) * 2);
            freqCount[diffCount - 1][0] = nums[i];
            freqCount[diffCount - 1][1] = 1;
        }
    }
    qsort(freqCount, diffCount, sizeof(int*), cmp2);
    *returnSize = k;
    int* ans = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; ++i) {
        ans[i] = freqCount[i][0];
    }
    return ans;
}