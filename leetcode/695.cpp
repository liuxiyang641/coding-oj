// https://leetcode.com/problems/max-area-of-island/
// 练习内容：DFS

int iDir[4] = {-1, 1, 0, 0};
int jDir[4] = {0, 0, -1, 1};

int calMaxAreaDFS(int** grid, int gridSize, int* gridColSize, int i, int j) {
    int count = 0;
    if(i < 0 || i >= gridSize || j < 0 || j >= (*gridColSize) || grid[i][j]==0) // 如果超过边界或者是0，或者是1已经访问过
        return count;
    count++;
    grid[i][j] = 0; // 对于已经访问过的grid直接赋值为0
    // 四个方向DFS
    for(int dir = 0; dir < 4; ++dir) {
        count += calMaxAreaDFS(grid, gridSize, gridColSize, i + iDir[dir], j + jDir[dir]);
    }
    return count;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int maxCount = 0;
    for(int i = 0; i<gridSize; ++i) {
        for(int j = 0; j < (*gridColSize); ++j) {
            int count = calMaxAreaDFS(grid, gridSize, gridColSize, i, j);
            maxCount = count > maxCount ? count : maxCount;
        }
    }
    return maxCount;
}