// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>

int main() {
    int a, x;
    while(scanf("%d %d", &a, &x)!=EOF) {
        int b, y, c, z;
        scanf("%d %d %d %d", &b, &y, &c, &z);
        int line = 0;
        long long allPerson = x;
        while(allPerson % b != y || allPerson % c != z || allPerson == 1) {
            line++;
            allPerson = line * a + x;
        }
        printf("%lld\n", allPerson);
    }
}