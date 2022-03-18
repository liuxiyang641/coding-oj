// https://leetcode.com/problems/factorial-trailing-zeroes/
// 求解n！有多少个因子10，转化为求解n！有多少个质因子5

int trailingZeroes(int n) {
    int ans = 0;
    while(n) {
        ans += n / 5;
        n /= 5;
    }
    return ans;
}