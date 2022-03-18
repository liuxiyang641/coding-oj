#include<stdio.h>
#include<string.h>

int main() {
    char s[201];
    int lowChar[26], upChar[26];
    
    while(gets(s)) {
        memset(lowChar, 0, sizeof(lowChar));
        memset(upChar, 0, sizeof(upChar));
        int preWord = 0;
        int wordCount = 0, charCount = 0;
        int len = strlen(s);
        for(int i = 0; i < len; ++i) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                lowChar[s[i] - 'a']++;
                preWord = 1;
                charCount++;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z') {
                upChar[s[i] - 'A']++;
                preWord = 1;
                charCount++;
            }
            else {
                // 是间隔符
                if(preWord) {
                    wordCount++;
                    preWord = 0;
                }
            }
        }
        wordCount += preWord; // 最后一个单词后面可能没有间隔符
        for(int i = 0; i < 26; ++i) {
            if(lowChar[i]) {
                printf("%c:%d\n", 'a' + i, lowChar[i]);
            }
        }
        for(int i = 0; i < 26; ++i) {
            if(upChar[i]) {
                printf("%c:%d\n", 'A' + i, upChar[i]);
            }
        }
        printf("%d\n", wordCount);
        printf("%d\n", charCount);
    }
}