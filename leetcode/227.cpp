// https://leetcode.com/problems/basic-calculator-ii/
// 四则表达式计算，使用两个栈，数字栈和操作符栈，遇到数字直接入栈，遇到操作符就和当前操作符栈栈顶比较，如果操作符栈栈顶优先级较高，就不断出栈和数字栈
// 进行计算，直到操作符栈为空或者栈顶的操作符优先级较小；如果是新的操作符优先级较高，则新的操作符入栈


#include<algorithm>
#include<string.h>
using namespace std;

int opOrder(char s) {
    if(s == '*' || s == '/') {
        return 2;
    }
    else if(s == '+' || s == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

int cal(int a, int b, char op) {
    switch (op)
    {
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '+':
        return a + b;
    case '-':
        return a - b;
    default:
        break;
    }
    return 0;
}

int calculate(char * s) {
    char opSta [100];
    int opLen = 0;
    int numSta [100];
    int numLen = 0;
    int len = strlen(s);
    int preNum = 0;
    bool numExixted = false;
    for(int i = 0; i < len; ++i) {
        if(s[i] <= '9' && s[i] >= '0') {
            preNum = preNum * 10 +  - '0' + s[i];
            numExixted = true;
        } 
        else {
            if(numExixted) {
                // 数字入栈
                numSta[numLen++] = preNum;
                preNum = 0;
                numExixted = false;
            }
            if(s[i] != ' ') {
                if(opLen == 0) {
                    opSta[opLen++] = s[i];
                }
                else {
                    // 如果栈不是空
                    while(opLen != 0 && opOrder(opSta[opLen - 1]) >= opOrder(s[i])) {
                        // 如果操作符栈不为空，并且栈顶优先级比当前操作符大，就出栈，进行运算
                        int b = numSta[--numLen];
                        int a = numSta[--numLen];
                        char opTop = opSta[--opLen];
                        int res = cal(a, b, opTop);
                        numSta[numLen++] = res;
                    }
                    opSta[opLen++] = s[i];
                }
            }
        }
    }
    // 输入最后的数字
    if(numExixted) {
        numSta[numLen++] = preNum;
        preNum = 0;
        numExixted = false;
    }
    // 清空操作符
    while(opLen) {
        int b = numSta[--numLen];
        int a = numSta[--numLen];
        char opTop = opSta[--opLen];
        int res = cal(a, b, opTop);
        numSta[numLen++] = res;
    }

    return numSta[0];
}