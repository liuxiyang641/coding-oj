// https://leetcode.com/problems/count-primes/
// 数质数

#include<algorithm>
#include<string.h>
using namespace std;

int countPrimes(int n) {
    bool* isPrime = (bool*)malloc(sizeof(bool) * (n + 1));
    for(int i = 0; i <= n; ++i) {
        isPrime[i] = true;
    }
    int count = 0;
    for(int i = 2; i < n; ++i) {
        if(isPrime[i]) {
            count++;
            for(int j = 2; i * j<=n; ++j) {
                isPrime[i * j] = false;
            }
        }
    }
    free(isPrime);
    return count;
}