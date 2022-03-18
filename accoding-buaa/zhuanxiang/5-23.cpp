#include<stdio.h>
#include<string.h>

int main() {
    char s[101];
    while(~scanf("%s", s)) {
        int len = strlen(s);
        for(int i = 0; i < len; ++i) {
            if(s[i] != '-') {
                printf("%c", s[i]);
            }
            else {
                if(i - 1 >= 0 && i + 1 < len) {
                    if(s[i - 1] < s[i + 1]) {
                        if( (s[i - 1] >= '0' && s[i + 1] <= '9') ||
                         (s[i - 1] >= 'a' && s[i + 1] <= 'z') ||
                         s[i - 1] >= 'A' && s[i + 1] <= 'Z' ) {
                             int newCount = s[i + 1] - s[i - 1] - 1;
                            for(int j = 1; j <= newCount; ++j) {
                                printf("%c", s[i - 1] + j);
                            }
                         }
                        else {
                            printf("%c", s[i]);
                        }
                    }
                    else {
                        printf("%c", s[i]);
                    }
                }
                else {
                    printf("%c", s[i]);
                }
            }
        }
        printf("\n");
    }
}