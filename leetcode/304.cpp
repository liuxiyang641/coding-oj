// https://leetcode.com/problems/range-sum-query-2d-immutable/
// 二维矩阵的前缀和

#include<vector>
using namespace std;

#include<vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> matrixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row0(n + 1, 0);
        matrixSum.push_back(row0);
        // 求当前右下角为i,j的矩阵元素和，sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]
        for(int i = 1; i <= m; ++i) {
            matrixSum.push_back(vector<int>{0});
            for(int j = 1; j <= n; ++j) {
                matrixSum[i].push_back(matrix[i - 1][j - 1] - matrixSum[i-1][j-1] + matrixSum[i][j-1] + matrixSum[i - 1][j]);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        // sum[i][j] - sum[i-1][j] - sum[i][j-1] + sum[i-1][j-1]
        int sumAns = matrixSum[row2][col2] - matrixSum[row2][col1 - 1] - matrixSum[row1 - 1][col2] + matrixSum[row1 - 1][col1 - 1];
        return  sumAns;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */