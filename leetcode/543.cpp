// https://leetcode.com/problems/diameter-of-binary-tree/
// 求解二叉树的直径，也就是最大的左右子树高度和

#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int calTreeHeight(struct TreeNode* root, int* maxDiameter) {
    if(!root) {
        return 0;
    }
    int leftDiameter = calTreeHeight(root->left, maxDiameter);
    int rightDiameter = calTreeHeight(root->right, maxDiameter);
    // 左右子树的高度之和，就是以root为根的树的最大直径
    int currentDiameter = leftDiameter + rightDiameter;
    if(currentDiameter > *maxDiameter) {
        *maxDiameter = currentDiameter;
    }
    leftDiameter++;
    rightDiameter++;
    return leftDiameter > rightDiameter ? leftDiameter : rightDiameter;
}


int diameterOfBinaryTree(struct TreeNode* root) {
    int maxDiameter = 0;
    calTreeHeight(root, &maxDiameter);
    return maxDiameter;
}