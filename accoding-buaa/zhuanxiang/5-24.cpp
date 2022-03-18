#include<stdio.h>
#include<string.h>

int main() {
    char s[11];
    while(~scanf("%s", s)) {
        long long ans = 0;
        for(int i = 0; i < strlen(s); ++i) {
            ans = ans * 26 + s[i] - 'A' + 1;
        }
        printf("%lld\n", ans);
    }
}