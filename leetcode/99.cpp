// https://leetcode.com/problems/recover-binary-search-tree/
// 利用BST的中序遍历是一个递增的数组，找到可能是错误的节点，然后交换位置
// 难点在于照清楚中序遍历中的错误的节点个数的规律，当前一个位置比当前位置大的时候，就发现了一处错误；如果只有一处错误，就只需要交换着两个
// 相邻的位置元素即可。如果发现了两处错误，就需要交换第一处错误的pre和第二处错误的root

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

void inorder(struct TreeNode* root, struct TreeNode** wrongPos1, struct TreeNode** wrongPos2, struct TreeNode** pre) {
    if(!root) {
        return;
    }
    inorder(root->left, wrongPos1, wrongPos2, pre);
    if((*pre) != NULL && (*pre)->val > root->val) {
        // 如果当前位置节点是一个候选的错误节点，并且在左子树没有找到错误
    // printf("%d %d\n", (*pre)->val, root->val);
        if(!(*wrongPos1)) {
            *wrongPos1 = *pre;
            *wrongPos2 = root; // 如果是整个中序排序只找到了一处错误，就是root和pre是错误的结点。否则的话，wrongPos2可能被替换
        }
        else {
            // 如果在左子树找到了错误，现在是第二处错误，可以直接返回
            *wrongPos2 = root;
            return;
        }
    }
    *pre = root;
    inorder(root->right, wrongPos1, wrongPos2, pre);
}

void recoverTree(struct TreeNode* root) {
    struct TreeNode** wrongPos1 = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    struct TreeNode** wrongPos2 = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    struct TreeNode** pre = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    *wrongPos1 = NULL;
    *wrongPos2 = NULL;
    *pre = NULL;
    inorder(root, wrongPos1, wrongPos2, pre);
    // printf("%d ", (*wrongPos2)->val);
    int tmp = (*wrongPos1)->val;
    (*wrongPos1)->val = (*wrongPos2)->val;
    (*wrongPos2)->val = tmp;
}