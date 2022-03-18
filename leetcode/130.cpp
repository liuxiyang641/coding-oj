// https://leetcode.com/problems/surrounded-regions/
// 矩阵的四个方向DFS搜索

#include<algorithm>
using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void filpToO(char** board, int boardSize, int* boardColSize, int i, int j, int** flipped) {
    if(i < 0 || i >= boardSize || j < 0 || j >= *boardColSize) {
        return;
    }
    // printf("%d %d\n", i, j);
    if(board[i][j] == 'X' || flipped[i][j] == -1) {
        return;
    }
    flipped[i][j] = -1;
    for(int d = 0; d < 4; ++d) {
        filpToO(board, boardSize, boardColSize, i + dir[d][0], j + dir[d][1], flipped);
    }
}

void solve(char** board, int boardSize, int* boardColSize) {
    int** flipped = (int**)malloc(sizeof(int*) * boardSize);
    for(int i = 0; i < boardSize; ++i) {
        flipped[i] = (int*)malloc(sizeof(int) * (*boardColSize));
        for(int j = 0; j < *boardColSize; ++j) {
            if(board[i][j] == 'X') {
                flipped[i][j] = -1;
            }
            else {
                flipped[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < (*boardColSize); ++i) {
        if(flipped[0][i] != -1 && board[0][i] == 'O') {
            filpToO(board, boardSize, boardColSize, 0, i, flipped);
        }
    }
    for(int i = 0; i < (*boardColSize); ++i) {
        if(flipped[boardSize - 1][i] != -1 && board[boardSize - 1][i] == 'O') {
            filpToO(board, boardSize, boardColSize, boardSize - 1, i, flipped);
        }
    }
    for(int i = 0; i < boardSize; ++i) {
        if(flipped[i][0] != -1 && board[i][0] == 'O') {
            filpToO(board, boardSize, boardColSize, i, 0, flipped);
        }
    }
    for(int i = 0; i < boardSize; ++i) {
        if(flipped[i][*boardColSize - 1] != -1 && board[i][*boardColSize - 1] == 'O') {
            filpToO(board, boardSize, boardColSize, i, *boardColSize - 1, flipped);
        }
    }
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < *boardColSize; ++j) {
            if(flipped[i][j] != -1 && board[i][j] == 'O') {
                board[i][j] = 'X';
                flipped[i][j] = -1;
            }
        }
    }
}