// https://leetcode.com/problems/n-queens/
// n皇后问题，依旧是回溯法，特点在于巧妙的分解问题，比如通过循环让每一行都互不干扰，只需要考虑放到第j列即可

#include<algorithm>
using namespace std;
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool isAllowed(int i, int j, int n, int* queenPos) {
    for(int s=0; s < i ; ++s) {
        // 如果前i-1行有第j列
        if(queenPos[s] == j) {
            return false;
        }
    }
    // 判断左斜和右斜根据LeetCode书上的内容，有个简便办法是给每个左斜和右斜和列都设置一个id，分别设置bool数组
    // 开始检查左斜
    for(int step = 1; (i - step) >= 0 && j - step >= 0; ++step) {
        // 如果前i-step行有第j-step列
        if(queenPos[(i - step)] == j - step) {
            return false;
        }
    }
    // 开始检查右斜
    for(int step = 1; (i - step) >= 0 && j + step < n; ++step) {
        // 如果前i-step行有第j+step列
        if(queenPos[(i - step)] == j + step) {
            return false;
        }
    }
    return true;
}

void queenPermu(int i, int n, int *queenPos, int** allQueenPos, int* returnSize) {
    if(i == n) {
        // 找到一种新的queen排列
        allQueenPos[*returnSize] = (int*)malloc(sizeof(int) * n);
        for(int i = 0; i < n; ++i) {
            allQueenPos[*returnSize][i] = queenPos[i];
        }
        (*returnSize)++;
        return;
    }
    // 第i行，尝试在第j列排行
    for(int j = 0; j < n; ++j) {
        if(isAllowed(i, j, n, queenPos)) {
            queenPos[i] = j; // 第i行选择了第j列
            // printf("%d %d\n", i, j);
            queenPermu(i + 1, n, queenPos, allQueenPos, returnSize);
        }
    }
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    int* queenPos = (int*)malloc(sizeof(int) * n);
    int** allQueenPos = (int**)malloc(sizeof(int*) * 1000);
    *returnSize = 0;
    queenPermu(0, n, queenPos, allQueenPos, returnSize);
    // printf("%d\n", *returnSize);
    char*** printQueen = (char***)malloc(sizeof(char**) * (*returnSize));
    for(int i = 0; i < (*returnSize); ++i) {
        printQueen[i] = (char**)malloc(sizeof(char*) * n);
        for(int j = 0; j < n; ++j) {
            printQueen[i][j] = (char*)malloc(sizeof(char) * (n+1));
            for(int k = 0; k < n; ++k) {
                // 第i种排列，第j行，是第k列为queen
                if(allQueenPos[i][j] == k) {
                    printQueen[i][j][k] = 'Q';
                }
                else {
                    printQueen[i][j][k] = '.';
                }
                printQueen[i][j][n] = '\0';
                // printf("%c ", printQueen[i][j][k]);
            }
        }
        
    }

    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i=0; i < (*returnSize); ++i) {
        (*returnColumnSizes)[i] = n;
    }
    // for(int i=0; i < (*returnSize); ++i) {
    //     printf("%d ", (*returnColumnSizes)[i]);
    // }
    free(queenPos);
    free(allQueenPos);
    
    return printQueen;
}