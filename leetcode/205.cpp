// https://leetcode.com/problems/isomorphic-strings/
// 判断两个字符是不是同构的，也就是说是不是存在唯一对应的办法，a->b，并且b不能重复，不能出现a->c或者d->b的情况
// 记住可以使用129的数组保存所有的asscii码，直接使用(int)进行类型转换

#include<algorithm>
#include<string.h>
using namespace std;

bool isIsomorphic(char * s, char * t) {
    int len = strlen(s);
    int map[129];
    bool used[129];
    for(int i = 0 ; i < 129; ++i) {
        map[i] = -1;
        used[i] = false;
    }
    for(int i = 0; i < len; ++i) {
        int keyS = (int)s[i];
        int keyT = (int)t[i];
        if(map[keyS] == -1) {
            if(used[keyT]) {
                return false;
            }
            else {
                map[keyS] = keyT;
                used[keyT] = true;
            }
        }
        else {
            if(map[keyS] != keyT) {
                return false;
            }
        }
    }
    return true;
}