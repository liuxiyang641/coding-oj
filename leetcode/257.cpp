// https://leetcode.com/problems/binary-tree-paths/

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

void findPath(char** allPath, int* returnSize, char* currentPath, int* currentLen, struct TreeNode* root) {
    int rootValLen = 0;
    int val = root->val;
    if(val < 0) {
        currentPath[*currentLen] = '-';
        *currentLen += 1;
        rootValLen++;
        val = -val;
    }
    char* tmp = (char*)malloc(sizeof(char) * 3);
    int tmpLen = 0;
    while(val) {
        tmp[tmpLen++] = '0' + val % 10;
        val /= 10;
    }
    for(int i = tmpLen - 1; i >=0; --i) {
        currentPath[*currentLen] = tmp[i];
        *currentLen += 1;
        rootValLen++;
    }
    free(tmp);
    if(root->left) {
        currentPath[*currentLen] = '-';
        *currentLen += 1;
        currentPath[*currentLen] = '>';
        *currentLen += 1;
        findPath(allPath, returnSize, currentPath, currentLen, root->left);
        *currentLen -= 2;
    }
    if(root->right) {
        currentPath[*currentLen] = '-';
        *currentLen += 1;
        currentPath[*currentLen] = '>';
        *currentLen += 1;
        findPath(allPath, returnSize, currentPath, currentLen, root->right);
        *currentLen -= 2;
    }
    if(root->left == NULL && root->right == NULL) {
        allPath[*returnSize] = (char*)malloc(sizeof(char) * (*currentLen + 1));
        for(int i = 0; i < *currentLen; ++i) {
            allPath[*returnSize][i] = currentPath[i];
        }
        allPath[*returnSize][*currentLen] = '\0';
        *returnSize += 1;
    }
    *currentLen -= rootValLen;
    return;
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** allPath = (char**)malloc(sizeof(char*) * 100);
    *returnSize = 0;
    char currentPath [400];
    int currentLen = 0;
    findPath(allPath, returnSize, currentPath, &currentLen, root);
    return allPath;
}