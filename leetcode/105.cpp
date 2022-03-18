// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// 利用先序和中序遍历来重建树
// 要点在于先序遍历和中序遍历的所需区间的对齐

#include<algorithm>
#include<string.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// 下面的方法可以简化的，根据总的区间长度，可以直接找到左右子树在前序遍历中的区间
struct TreeNode* buildTreeT(int* preorder, int* preorderBegin, int* inorder, int inorderSize) {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[*preorderBegin];
    *preorderBegin += 1;
    int rootPos;
    // 下面这一步，可以使用hash表unordered_map进一步记录位置
    for(int i = 0; i < inorderSize; ++i) {
        if(inorder[i] == root->val) {
            rootPos = i;
            break;
        }
    }
    if(rootPos == 0) {
        root->left = NULL;
    }
    else {
        root->left = buildTreeT(preorder, preorderBegin, inorder, rootPos);
    }
    if(rootPos == inorderSize - 1) {
        root->right = NULL;
    }
    else {
        root->right = buildTreeT(preorder, preorderBegin, inorder + rootPos + 1, inorderSize - 1 - rootPos);
    }
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preorderBegin = 0;
    struct TreeNode* ans = buildTreeT(preorder, &preorderBegin, inorder, inorderSize);
    return ans;
}