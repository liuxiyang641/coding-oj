// https://leetcode.com/problems/rotate-image/
// 矩阵旋转90度操作，比较麻烦的是两点，一个是如何判断旋转前与旋转后的位置对应关系，一个是如何避免重复计算 
// 旋转操作，通过寻找规律可以发现，i,j->j,n-1-i，这样对于原位置i,j，跳转四次后又会回到原来的位置上
// 由于每个i,j都是直接操作四个位置，所以要避免把已经旋转好的元素再次旋转，为了实现这一点，采用了布尔数组记录是否旋转
// 但是更简单的方法在LeetCode书上，可以通过寻找规律，发现只需要i->n/2, j->i-n-i即可

#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        bool isRotated[21][21] = {false};
        int n = matrix.size() - 1;
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= n; ++j) {
                if(!isRotated[i][j]) {
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[n-j][i];
                    matrix[n-j][i] = matrix[n-i][n-j];
                    matrix[n-i][n-j] = matrix[j][n-i];
                    matrix[j][n-i] = tmp;
                    isRotated[i][j] = true;
                    isRotated[n-j][i] = true;
                    isRotated[n-i][n-j] = true;
                    isRotated[j][n-i] = true;
                }
            }
        }
    }
};