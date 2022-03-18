// https://leetcode.com/problems/add-strings/
// 大整数加法

#include<string.h>
#include<algorithm>
using namespace std;

char * addStrings(char * num1, char * num2) {
    int * int_sum = (int*)malloc(sizeof(int) * 10010);
    int len1 = strlen(num1), len2 = strlen(num2); 
    int * int_num1 = (int*)malloc(sizeof(int) * len1);
    int * int_num2 = (int*)malloc(sizeof(int) * len2);
    memset(int_sum, 0, sizeof(int_sum));
    for(int i = 0; i < len1; ++i) {
        int_num1[i] = num1[len1 - 1 - i] - '0';
        // printf("%d ", int_num1[i]);
    }
    for(int i = 0; i < len2; ++i) {
        int_num2[i] = num2[len2 - 1 - i]  - '0';
    }
    int tmp, carry = 0, lenSum = 0;
    for(int i = 0; i < len1 && i < len2; ++i) {
        tmp = int_num1[i] + int_num2[i] + carry;
        carry = tmp / 10;
        int_sum[lenSum++] = tmp % 10;
    }
    while(lenSum < len1) {
        tmp = int_num1[lenSum] + carry;
        carry = tmp / 10;
        int_sum[lenSum++] = tmp % 10;
    }
    while(lenSum < len2) {
        tmp = int_num2[lenSum] + carry;
        carry = tmp / 10;
        int_sum[lenSum++] = tmp % 10;
    }
    while(carry != 0) {
        tmp = carry;
        carry = tmp / 10;
        int_sum[lenSum++] = tmp % 10;
    }
    char* sum = (char*)malloc(sizeof(char) * (lenSum + 1));
    for(int i = 0; i < lenSum; ++i) {
        sum[i] = int_sum[lenSum - 1 - i] + '0';
    }
    sum[lenSum] = 0;
    free(int_sum);
    free(int_num1);
    free(int_num2);
    return sum;
}