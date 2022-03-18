// https://leetcode.com/problems/binary-tree-preorder-traversal/
// 先序遍历的两种写法，递归和迭代


#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 下面是递归的写法
void preorder(struct TreeNode* root, int* preorderArray, int* returnSize) {
    if(!root) {
        return;
    }
    preorderArray[*returnSize] = root->val;
    *returnSize += 1;
    preorder(root->left, preorderArray, returnSize);
    preorder(root->right, preorderArray, returnSize);
}

// 下面是迭代的写法
void preorderItera(struct TreeNode* root, int* preorderArray, int* returnSize) {
    if(!root) {
        return;
    }
    struct TreeNode** sta = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 110);
    int top = -1;
    sta[++top] = root;
    while(top != -1) {
        struct TreeNode* tmpTopNode = sta[top--];
        preorderArray[*returnSize] = tmpTopNode->val;
        *returnSize += 1;
        // 注意，栈是后进先出，先序遍历先访问左结点再访问右结点，因此先入栈右结点，再入栈左结点
        if(tmpTopNode->right)
            sta[++top] = tmpTopNode->right;
        if(tmpTopNode->left)
            sta[++top] = tmpTopNode->left;
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* ans = (int*)malloc(sizeof(int) * 110);
    *returnSize = 0;
    // preorder(root, ans, returnSize);
    preorderItera(root, ans, returnSize);
    return ans;
}