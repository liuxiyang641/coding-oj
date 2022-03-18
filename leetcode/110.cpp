// https://leetcode.com/problems/balanced-binary-tree/
// 判断一棵二叉树是不是平衡的，先判断左右子树是否平衡，再判断左右子树都平衡的情况下，当前节点是否平衡

#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int treeBalance(struct TreeNode* root) {
    if(!root) {
        return 0;
    }
    int leftHeight = treeBalance(root->left);
    int rightHeight = treeBalance(root->right);
    if(leftHeight == -1 || rightHeight == -1) {
        return -1;
    }
    if(abs(leftHeight - rightHeight) >= 2) {
        return -1;
    }
    leftHeight++;
    rightHeight++;
    return leftHeight > rightHeight ? leftHeight : rightHeight;
}

bool isBalanced(struct TreeNode* root) {
    return treeBalance(root) != -1;
}