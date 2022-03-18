// https://leetcode.com/problems/trim-a-binary-search-tree/
// 根据一个区间删除BST树的树节点，左右子树的裁剪和当前子树的裁剪是一样的，可以使用递归，先裁剪好左右子树，再决定当前子树是否要裁剪，并且返回裁剪后的最终结果

#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    if(!root) {
        return NULL;
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    // 如果当前根节点也需要裁剪，就需要把左右子树变为新的当前根节点
    if(root->val < low || root->val > high) {
        if(root->left) {
            root = root->left;
        }
        else if(root->right) {
            root = root->right;
        }
        else {
            root = NULL;
        }
    }
    return root;
}