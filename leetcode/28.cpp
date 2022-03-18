// https://leetcode.com/problems/implement-strstr/
// 寻找后一个字符串是否是前一个字符串的子串

#include<algorithm>
#include<string.h>
using namespace std;

// 最朴素的解法
int strStr(char * haystack, char * needle) {
    int len1 = strlen(haystack), len2 = strlen(needle);
    if(len2 == 0) {
        return 0;
    }
    if(len1 == 0) {
        return -1;
    }
    for(int i = 0; i < len1; ++i) {
        int j = 0;
        for(; j < len2; ++j) {
            if(haystack[i + j] != needle[j]) {
                break;
            }
        }
        if(j == len2) {
            return i;
        }
    }
    return -1;
}

// 下面尝试使用KMP算法

void getNext(int* next, char* s) {
    int j = -1; // j是已经匹配的字符串长度
    next[0] = -1;
    int len = strlen(s);
    for(int i = 1; i < len; ++i) {
        // 尝试寻找新的可以匹配的前缀
        while(j != -1 && s[i] != s[j + 1]) {
            j = next[j];
        }
        // 如果找到了新的匹配前缀
        if(s[j + 1] == s[i]) {
            j++;
        }
        next[i] = j; // 位置i的前缀是j，如果j不是-1，即字符串0-i和0-j从右端是可以对齐的
    }
}

int strStr(char * haystack, char * needle) {
    int len1 = strlen(haystack), len2 = strlen(needle);
    if(len2 == 0) {
        return 0;
    }
    if(len1 == 0) {
        return -1;
    }
    int* next = (int*)malloc(sizeof(int) * len2);
    getNext(next, needle);
    int j = -1;
    for(int i = 0; i < len1; ++i) {
        // j是已经匹配的needle的长度，尝试继续匹配；如果无法匹配的话，就用next后退
        while(j != -1 && haystack[i] != needle[j + 1]) {
            j = next[j];
        }
        // 如果至少有一个匹配的
        if(haystack[i] == needle[j + 1]) {
            j++;
        }
        if(j == len2 - 1) {
            return i - len2 + 1;
        }
    }
    return -1;
}