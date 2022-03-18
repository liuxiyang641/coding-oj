// https://leetcode.com/problems/shortest-bridge/
// 使用queue实现的BFS，最大的收获是使用stl中的queue的代价要比单纯的DFS递归实现大，如果适合使用DFS，尽量使用DFS，当然实际中DFS一般使用stack来
// 实现，不过在刷题中，还是喜欢递归的写法

#include<queue>
#include<vector>
using namespace std;
class Solution {
private:
    int dirIJ[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    void DFSIslandMark(int i, int j, vector<vector<int>>& grid, int gridSize, queue<pair<int, int>>& zeroBoardPoints) {
        if(i<0 || i>=gridSize || j<0 || j>=gridSize) {
            return;
        }
        if(grid[i][j] == 0) {
            grid[i][j] = -1;
            zeroBoardPoints.push(make_pair(i, j));
            return;
        }
        if(grid[i][j] == 1) {
            grid[i][j] = 2;
            for(int dir=0; dir<4; ++dir) {
                int tmpI = i + this->dirIJ[dir][0];
                int tmpJ = j + this->dirIJ[dir][1];
                DFSIslandMark(tmpI, tmpJ, grid, gridSize, zeroBoardPoints);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int gridSize = grid.size();
        queue<pair<int, int>> zeroBoardPoints;
        bool breakLoop = false;
        // printf("1");
        for(int i=0;i<gridSize;++i) {
            if(breakLoop) break;
            for(int j=0;j<gridSize;++j) {
                if(grid[i][j] == 1) {
                    // 开始标记第一个island
                    // queue<pair<int, int>> q;
                    // q.push(make_pair(i, j));
                    // while (!q.empty())
                    // {
                    //     pair<int, int> p = q.front();
                    //     q.pop();
                    //     grid[p.first][p.second] = 2;
                    //     for(int dir=0; dir<4; ++dir) {
                    //         int tmpI = p.first + dirIJ[dir][0];
                    //         int tmpJ = p.second + dirIJ[dir][1];
                    //         if(tmpI<0 || tmpI>=gridSize || tmpJ<0 || tmpJ>=gridSize) {
                    //             continue;
                    //         }
                    //         if(grid[tmpI][tmpJ] == 0) {
                    //             zeroBoardPoints.push(make_pair(tmpI, tmpJ));
                    //             grid[tmpI][tmpJ] = -1; // 标记对应的邻边0已经加入队列
                    //         }
                    //         if(grid[tmpI][tmpJ] == 1) {
                    //             q.push(make_pair(tmpI, tmpJ));
                    //         }
                    //     }
                    // }
                    DFSIslandMark(i, j, grid, gridSize, zeroBoardPoints);
                    breakLoop = true;
                    break;
                }
            }
        }
        // for(int i=0;i<gridSize;++i) {
        //     for(int j=0;j<gridSize;++j) {
        //         printf("%d ", grid[i][j]);
        //     }
        // }
        // 开始从所有的邻边0，开始BFS
        int step = 1;
        while(!zeroBoardPoints.empty()) {
            int queueSize = zeroBoardPoints.size();
            while(queueSize--) {
                pair<int, int> p = zeroBoardPoints.front();
                zeroBoardPoints.pop();
                for(int dir=0; dir<4; ++dir) {
                    int tmpI = p.first + this->dirIJ[dir][0];
                    int tmpJ = p.second + this->dirIJ[dir][1];
                    if(tmpI<0 || tmpI>=gridSize || tmpJ<0 || tmpJ>=gridSize) {
                        continue;
                    }
                    if(grid[tmpI][tmpJ] == 0) {
                        zeroBoardPoints.push(make_pair(tmpI, tmpJ));
                        grid[tmpI][tmpJ] = -1; // 新的0已经加入队列
                    }
                    if(grid[tmpI][tmpJ] == 1) {
                        return step; // 找到编号为1的island
                    }
                }
            }
            step++;
        }
        return step;
    }
};