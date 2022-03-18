// https://leetcode.com/problems/symmetric-tree/
// 判断一棵树是不是对称树
// 一开始希望通过判断中序是否是对称的，但是结果发现因为有空节点的存在，是的中序遍历的结果不一定唯一的对应树，也就不能直接判断是否是对称树
// 使用递归的思路，判断左右子节点是否相等，如果相等再判断左->左和右->右，左->右和右->左

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

bool checkSubTreeSym(struct TreeNode* left, struct TreeNode* right) {
    if(!left && !right) {
        return true;
    }
    if(left && right) {
        if(left->val != right->val) {
            return false;
        }
        return checkSubTreeSym(left->left, right->right) && checkSubTreeSym(left->right, right->left);
    }
    else {
        return false;
    }
}

bool isSymmetric(struct TreeNode* root) {
    return checkSubTreeSym(root->left, root->right);
}