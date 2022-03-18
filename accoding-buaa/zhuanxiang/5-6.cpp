#include<stdio.h>

int main() {
    int visited[11];
    for(int i = 1; i <= 10; ++i) {
        visited[i] = 0;
    }
    int count = 1000;
    int current = 10, space = 0;
    int success = 1;
    int allVisited = 0;
    while(count--) {
        if(!visited[current]) {
            visited[current] = 1;
            allVisited++;
        }
        current = (current + (space++)) % 10 + 1;
        if(allVisited == 10) {
            success = 0;
            break;
        }
    }
    if(!success) {
        printf("NIE\n");
    }
    else {
        for(int i = 1; i <= 10; ++i) {
            if(visited[i] == 0) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}