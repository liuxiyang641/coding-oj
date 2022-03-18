// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<string.h>
#include<stdio.h>

int main() {
    char s1[1000], s2[5];
    while(scanf("%s %s", s1, s2)!=EOF) {
        int len1 = strlen(s1);
        for(int i = 0; i < len1; ++i) {
            if(s1[i] <= 'z' && s1[i] >= 'a') {
                s1[i] = s1[i] + 'A' - 'a';
            }
            else if(s1[i] <= 'Z' && s1[i] >= 'A') {
                s1[i] = s1[i] - ('A' - 'a');
            }
        }
        for(int i = 0; i < 4; ++i) {
            if(s2[i] <= 'z' && s2[i] >= 'a') {
                s2[i] = s2[i] + 'A' - 'a';
            }
            else if(s2[i] <= 'Z' && s2[i] >= 'A') {
                s2[i] = s2[i] - ('A' - 'a');
            }
        }
        printf("%s\n%s\n", s1, s2);
    }
}