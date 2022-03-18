// https://leetcode.com/problems/power-of-three/submissions/
// 求n是否是3为底的指数值

#include<math.h>
using namespace std;

bool isPowerOfThree(int n){
    if(n == 0) return false;
    while(n != 1) {
        if(n % 3 == 0) {
            n /= 3;
        }
        else {
            return false;
        }
    }
    return true;
}

// 下面是leetcode书上的方法，通过换底公式，判断log_3^n的结果是否为整数
bool isPowerOfThreeT(int n){
    return fmod(log10(n) / log10(3), 1) == 0;
}