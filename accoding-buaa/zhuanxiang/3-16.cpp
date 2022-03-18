// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>
#include<string.h>

int main() {
    char s[110];
    while (scanf("%s", s)!=EOF)
    {
        int len = strlen(s);
        for(int i = 0; i < len; ++i) {
            printf("%c", s[i] + 4);
        }
        printf("\n");
    }
}