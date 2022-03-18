// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// 寻找树的最大深度，使用递归的写法，取左右子树的最大深度+1即可

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if(!root) {
        return 0;
    }
    if(!root->right && !root->left) {
        return 1;
    }
    int leftDepth = maxDepth(root->left) + 1;
    int rightDepth = maxDepth(root->right) + 1;
    return rightDepth > leftDepth ? rightDepth : leftDepth;
}