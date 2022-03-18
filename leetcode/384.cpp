// https://leetcode.com/problems/shuffle-an-array/
// 随机洗牌，输出随机打乱的排列组合，根据LeetCode上的写法，利用Fisher-Yates洗牌算法实现

#include<algorithm>
using namespace std;

typedef struct {
    int* nums;
    int len;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution* solu = (Solution*)malloc(sizeof(Solution));
    solu->nums = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; ++i) {
        solu->nums[i] = nums[i];
    }
    solu->len = numsSize;
    return solu;
}

int* solutionReset(Solution* obj, int* retSize) {
    int* ans = (int*)malloc(sizeof(int) * obj->len);
    *retSize = obj->len;
    for(int i = 0; i < obj->len; ++i) {
        ans[i] = obj->nums[i];
    }
    return ans;
}

int* solutionShuffle(Solution* obj, int* retSize) {
    int* ans = (int*)malloc(sizeof(int) * obj->len);
    *retSize = obj->len;
    for(int i = 0; i < obj->len; ++i) {
        ans[i] = obj->nums[i];
    }
    for(int i = 0; i < obj->len - 1; ++i) {
        // 每次随机取出一个数，放到前面
        int pos = rand() % (obj->len - i);
        int tmp = ans[i];
        ans[i] = ans[i + pos];
        ans[i + pos] = tmp;
        // swap(ans[i], ans[i + pos]);
    }
    return ans;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 
 * int* param_2 = solutionShuffle(obj, retSize);
 
 * solutionFree(obj);
*/