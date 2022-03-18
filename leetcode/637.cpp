// https://leetcode.com/problems/average-of-levels-in-binary-tree/
// 计算tree每一层的平均值，层次搜索/广度优先搜索

#include<algorithm>
#include<string.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    double* average = (double*)malloc(sizeof(double) * 10010);
    int len1 = 0, len2 = 0;
    struct TreeNode* nodesQue [10001];
    struct TreeNode* tmpQue [10001];
    nodesQue[len1++] = root;
    *returnSize = 0;
    while (len1)
    {
        int nodeCount = 0;
        double sum = 0.0;
        while (len1) {
            struct TreeNode* tmpNode = nodesQue[--len1];
            sum += tmpNode->val;
            nodeCount++;
            if(tmpNode->left)
                tmpQue[len2++] = tmpNode->left;
            if(tmpNode->right)
                tmpQue[len2++] = tmpNode->right;
        }
        average[*returnSize] = sum / nodeCount;
        *returnSize += 1;
        while(len2) {
            nodesQue[len1++] = tmpQue[--len2];
        }
    }
    return average;
}