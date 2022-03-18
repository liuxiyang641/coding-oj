// https://leetcode.com/problems/base-7/
// 10进制转为7进制，并且输出

#include<algorithm>
using namespace std;

char * convertToBase7(int num){
    if(num == 0) { // 注意边界情况处理
        return "0";
    }
    char* res = (char*)malloc(sizeof(char) * (10010));
    bool isNeg = num < 0 ? true : false;
    num = num < 0 ? -num : num;
    int count = 0;
    while(num != 0) {
        res[count++] = (num % 7) + '0';
        num /= 7;
    }
    char* resRev;
    if(isNeg) {
        resRev = (char*)malloc(sizeof(char) * (count + 2));
        resRev[0] = '-';
        for(int i = 1; i <= count; ++i) {
            resRev[i] = res[(count - 1) - (i - 1)];
        }
        // 注意字符串最后一位设置为0，否则会报错
        resRev[count + 1] = 0;
    }
    else {
        resRev = (char*)malloc(sizeof(char) * (count + 1));
        for(int i = 0; i < count; ++i) {
            resRev[i] = res[(count - 1) - (i)];
        }
        resRev[count] = 0;
    }
    free(res);
    return resRev;
}