// https://leetcode.com/problems/word-search/
// 在一个grid矩阵中，寻找是否有对应的字符
// 核心思想是，如果当前节点为起点没有找到对应的匹配字符串，需要回复状态，让当前节点在后续的DFS中可以被再次访问

#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int dirI[4] = {-1, 1, 0, 0};
int dirJ[4] = {0, 0, -1, 1};

bool DFS(int i, int j, char** board, int boardSize, int* boardColSize, char * word, int pos, int strLen, bool** visited) {
    if(pos == strLen) {
        return true;
    }
    // 如果越界
    if(i < 0 || i >= boardSize || j < 0 || j >= (*boardColSize)) {
        return false;
    }
    // 如果下一步已经访问或者无法继续相等当前pos上的字符
    if(visited[i][j] == true || board[i][j]!=word[pos]) {
        return false;
    }
    visited[i][j] = true;
    bool findWord = false;
    for(int dir=0; dir < 4; ++dir) {
        findWord = DFS(i + dirI[dir], j + dirJ[dir], board, boardSize, boardColSize, word, pos + 1, strLen, visited);
        if(findWord) {
            return true;
        }
    }
    // 一直没有找到剩余的word字符，回复当前节点的false状态
    visited[i][j] = false;
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int len = strlen(word);
    bool findWord = false;
    bool** visited = (bool**)malloc(sizeof(bool*) * boardSize);
    for(int i=0;i<boardSize;++i) {
        visited[i] = (bool*)malloc(sizeof(bool) * (*boardColSize));
        for(int j=0; j < (*boardColSize); ++j) {
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < (*boardColSize); ++j) {
            if(board[i][j] == word[0]) {
                findWord = DFS(i, j, board, boardSize, boardColSize, word, 0, len, visited);
                if(findWord) {
                    return true;
                }
            }
        }
    }
    return false;
}