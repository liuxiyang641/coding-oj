// https://leetcode.com/problems/sort-characters-by-frequency/
// 按照数组出现元素（大小写字母和数字）的频率，降序排序

#include<algorithm>
#include<string.h>
using namespace std;

typedef struct {
    char c;
    int count;
} node;

int cmp(const void* a, const void* b) {
    node* tmpa = (node*)a, *tmpb = (node*)b;
    // 出现次数多的在前
    return tmpb->count - tmpa->count;
}

char * frequencySort(char * s){
    int* sta = (int*)malloc(sizeof(int) * (26 * 2 + 10));
    int len = strlen(s);
    for(int i = 0; i < 62; ++i) {
        sta[i] = -1;
    }
    // 统计各个元素出现频率
    for(int i = 0; i < len; ++i) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            if(sta[s[i] - 'a'] == -1) {
                sta[s[i] - 'a'] = 1;
            } 
            else {
                sta[s[i] - 'a']++;
            }
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            if(sta[s[i] - 'A' + 26] == -1) {
                sta[s[i] - 'A' + 26] = 1;
            }
            else {
                sta[s[i] - 'A' + 26]++;
            }
        }
        else {
            if(sta[s[i] - '0' + 52] == -1) {
                sta[s[i] - '0' + 52] = 1;
            }
            else {
                sta[s[i] - '0' + 52]++;
            }
        }
    }
    // 转化为要排序的结构体
    node freqChar[26 * 2 + 10];
    int charCount = 0;
    for(int i = 0; i < 26; ++i) {
        if(sta[i] != -1) {
            freqChar[charCount].c = 'a' + i;
            freqChar[charCount].count = sta[i];
            charCount++;
        }
    }
    
    for(int i = 26; i < 52; ++i) {
        if(sta[i] != -1) {
            freqChar[charCount].c = 'A' + i - 26;
            freqChar[charCount].count = sta[i];
            charCount++;
        }
    }
    
    for(int i = 52; i < 62; ++i) {
        if(sta[i] != -1) {
            freqChar[charCount].c = '0' + i - 52;
            freqChar[charCount].count = sta[i];
            charCount++;
        }
    }
    // 按照频率进行排序
    qsort(freqChar, charCount, sizeof(node), cmp);
    char* ans = (char*)malloc(sizeof(char) * (len + 1));
    int ansLen = 0;
    for(int i = 0; i < charCount; ++i) {
        while(freqChar[i].count--) {
            ans[ansLen++] = freqChar[i].c;
        }
    }
    ans[len] = '\0';
    return ans;
}