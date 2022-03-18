// https://leetcode.com/problems/valid-anagram/
// 判断两个字符是不是由完全相同的字符组成的

#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

bool isAnagram(char * s, char * t) {
    int len1 = strlen(s), len2 = strlen(t);
    int isExisted1[26] = {0};
    int isExisted2[26] = {0};
    for(int i = 0; i < len1; ++i) {
        isExisted1[s[i] - 'a']++;
    }
    for(int i = 0; i < len2; ++i) {
        isExisted2[t[i] - 'a']++;
    }
    for(int i = 0; i < 26; ++i) {
        if(isExisted2[i] != isExisted1[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    char* s1, s2[2];
    while(scanf("%s %s", s1, s2)) {
        printf("%d\n", isAnagram(s1, s2));
    }
}