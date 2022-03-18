#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a * a + b * b == c * c) {
            printf("Yes\n");
            continue;
        }
        if(a * a + c * c == b * b) {
            printf("Yes\n");
            continue;
        }
        if(c * c + b * b == a * a) {
            printf("Yes\n");
            continue;
        }
        printf("No\n");
    }

}