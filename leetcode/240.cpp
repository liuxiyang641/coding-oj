// https://leetcode.com/problems/search-a-2d-matrix-ii/
// 寻找在一个行值递增、列值递增的矩阵中，是否存在对应元素，
// LeetCode书上的解法是从矩阵右上角开始搜索，个人在想的时候没有考虑到这一点而是只考虑到了从左上角和右下角搜索

#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        // bool smallRow[m] = {true}, smallCol[n] = {true};
        int bigCol = n;
        if (matrix[m-1][n-1] < target || matrix[0][0] > target) {
            return false;
        }
        for(int i = 0; i < m; ++i) {
            if(matrix[i][0] <= target && matrix[i][n-1] >= target) {
                for(int j = 0; j < bigCol; ++j) {
                    if(matrix[i][j]==target) {
                        return true;
                    } else if(matrix[i][j]>target) {
                        // 如果某一列大于target，包括这一列往后的所有列都不需要再比较了
                        bigCol = j;
                    }
                }
            }
            else if(matrix[i][0] > target) {
                // 如果当前行最小值大于target，就不存在target了
                return false;
            }
        }
        return false;
    }
};