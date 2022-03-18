// https://leetcode.com/problems/sum-of-square-numbers/
// 双指针，计算a^2+b^2=c，核心是不断检查b能否是某个整数的平方，使用二分查找即可
// 需要特别注意为了防止平方运算超出int范围，所有涉及平方操作的变量，都使用long long保存

#include<algorithm>
using namespace std;

bool checkSquareRoot(long long x) {
    long long l = 0, r = x;
    // 注意下面不能是l==r，因为这样计算出来的mid会等于l和r，可能导致后面l和r继续相等，死循环
    while(l < r) {
        long long mid = l + (r - l) / 2;
        if(mid * mid == x) {
            return true;
        }
        else if(mid * mid < x) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    if(l * l == x) {
        return true;
    }
    return false;
}

bool judgeSquareSum(int c) {
    for(long long a = 0; a * a <= c; ++a) {
        long long b = c - a * a;
        if(checkSquareRoot(b)) {
            return true;
        }
    }
    return false;
}