// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
// 双指针，判断一个string是不是另一个string的子序列

#include<algorithm>
#include<string.h>
using namespace std;

bool isSubstring(char* s, char* dic) {
    int len1 = strlen(s), len2 = strlen(dic);
    int p1 = 0, p2 = 0;
    while(p1 < len1 && p2 < len2) {
        if(s[p1] == dic[p2]) {
            // 如果匹配到了dic最后一位
            if(p2 == len2 - 1) {
                return true;
            }
            p1++;
            p2++;
        }
        else {
            p1++;
        }
    }
    return false;
}

int cmp(const void* a, const void* b) {
    char* tmpa = *(char**)a, *tmpb = *(char**)b;
    int len1 = strlen(tmpa), len2 = strlen(tmpb);
    // 长度大的在前
    if(len1 > len2) {
        return -1;
    }
    else if(len1 < len2) {
        return 1;
    }
    else {
        for(int i = 0; i < len1; ++i) {
            // 字典序小的在前
            if(tmpa[i] < tmpb[i]) {
                return -1;
            }
            else if(tmpa[i] > tmpb[i]) {
                return 1;
            }
        }
        return 0;
    }
}

char * findLongestWord(char * s, char ** dictionary, int dictionarySize) {
    qsort(dictionary, dictionarySize, sizeof(char*), cmp);
    for(int i = 0; i < dictionarySize; ++i) {
        if(isSubstring(s, dictionary[i])) {
            return dictionary[i];
        }
    }
    char* empty = (char*)malloc(sizeof(char));
    empty[0] = '\0';
    return empty;
}