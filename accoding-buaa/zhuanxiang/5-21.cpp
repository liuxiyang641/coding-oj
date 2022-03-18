#include<stdio.h>
#include<string.h>

int main() {
    char a[101], b[101];
    while(~scanf("%s %s", a, b)) {
        int len1 = strlen(a);
        int len2 = strlen(b);
        int ans = 0;
        for(int i = 0; i <= len1 - len2; ++i) {
            int j = 0;
            for(; j < len2; ++j) {
                if(a[i + j] != b[j]) {
                    break;
                }
            }
            if(j == len2) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}