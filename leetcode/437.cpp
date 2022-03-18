// https://leetcode.com/problems/path-sum-iii/
// 寻找树的不同路径上，子路径和等于目标值的路径数量
// 思路：配合DFS，计算以不同node为根结点的满足要求的路径数量

#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int calPath(struct TreeNode* root, int targetSum) {
    if(!root) {
        return 0;
    }
    int leftNum = calPath(root->left, targetSum - root->val);
    int rightNum = calPath(root->right, targetSum - root->val);
    int curNum = root->val == targetSum ? 1 : 0;
    return leftNum + rightNum + curNum;
}

void DFS(struct TreeNode* root, int targetSum, int* pathCount) {
    if(!root) {
        return;
    }
    *pathCount += calPath(root, targetSum);
    DFS(root->left, targetSum, pathCount);
    DFS(root->right, targetSum, pathCount);
}

int pathSum(struct TreeNode* root, int targetSum) {
    int pathCount = 0;
    DFS(root, targetSum, &pathCount);
    return pathCount;
}