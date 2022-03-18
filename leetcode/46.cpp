// https://leetcode.com/problems/permutations/
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
// 回溯法，记录当前问题状态，然后修改，递归子问题之后，还原当前问题的状态，开始下一个子问题

#include<algorithm>
using namespace std;
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int combCount = 0;

void combing(int **combiations, int* currentComb, int pos, int idx, int k, int n) {
    if(pos == k) {
        combiations[combCount] = (int*)malloc(sizeof(int) * k);
        for(int i = 0; i < k; ++i) {
            combiations[combCount][i] = currentComb[i];
        }
        combCount++;
        return;
    }
    for(int i = idx; i <= n; ++i) {
        currentComb[pos] = i;
        // 组合元素i后续的数字都要比当前的数字i大，这样就保证了唯一性
        combing(combiations, currentComb, pos + 1, i + 1, k, n);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int tmp_n = n, tmp_k = k;
    // int A_nk = 1, A_kk = 1;
    // while (tmp_n >= (n - k + 1))
    // {
    //     A_nk *= (tmp_n--); 
    // }
    // while (tmp_k > 1)
    // {
    //     A_kk *= (tmp_k--); 
    // }
    // // 计算组合数
    // *returnSize = A_nk / A_kk;
    int** combiations = (int**)malloc(sizeof(int*) * 10000);
    for(int i=0;i<(*returnSize);++i) {
        combiations[i] = (int *)malloc(sizeof(int) * k);
    }

    combCount = 0;
    int* currentComb = (int*)malloc(sizeof(int) * k);
    combing(combiations, currentComb, 0, 1, k, n);
    
    *returnSize = combCount;
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for(int i=0;i<(*returnSize);++i) {
        (*returnColumnSizes)[i] = k;
    }
    return combiations;
}