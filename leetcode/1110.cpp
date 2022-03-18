// https://leetcode.com/problems/delete-nodes-and-return-forest/
// 返回一棵树删除多个不同的节点之后的结果，是多个树的集合
// 思路：删除左右子树上应该删除的节点，然后判断当前根结点是否应该删除，如果当前根结点应该删除，就把左右子树新增到森林集合中去
// 需要注意的是，需要特别判断是否一开始树的根结点是否要最后放入
// 另外的经验是，不要使用memset！！！

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

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

void delNodesT(struct TreeNode** rootNodes, struct TreeNode** root, bool* to_delete, int* returnSize) {
    if(!(*root)) {
        return;
    }
    if((*root)->left) {
        delNodesT(rootNodes, &(*root)->left, to_delete, returnSize);
    }
    if((*root)->right) {
        delNodesT(rootNodes, &(*root)->right, to_delete, returnSize);
    }
    // 如果要删除当前根结点，就需要判断是否增加左右子树的新子树
    if(to_delete[(*root)->val]) {
        if((*root)->left) {
            if(!to_delete[(*root)->left->val]) {
                // 新增左子树为根结点的tree
                rootNodes[*returnSize] = (*root)->left;
                *returnSize += 1;
            }
        }
        if((*root)->right) {
            if(!to_delete[(*root)->right->val]) {
                // 新增右子树为根结点的tree
                rootNodes[*returnSize] = (*root)->right;
                *returnSize += 1;
            }
        }
        *root = NULL;
    }
}

struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize) {
    bool* deleted = (bool*)malloc(sizeof(bool) * 1010);
    for(int i = 0; i < 1010; ++i) {
        deleted[i] = false;
    }
    for(int i = 0; i < to_deleteSize; ++i) {
        deleted[to_delete[i]] = true;
    }
    // printf("%d ", deleted[10]);
    struct TreeNode** ans = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    *returnSize = 0;
    delNodesT(ans, &root, deleted, returnSize);
    // 判断根结点是否要最后放进去森林集合
    if(root) {
        ans[*returnSize] = root;
        *returnSize += 1;
    }
    return ans;
}