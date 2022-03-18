#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int n;
    double x[101], y[101];
    while(~scanf("%d", &n)) {
        char s[1001];
        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            sscanf(s, "(%lf,%lf)", &x[i], &y[i]);
        }
        double theta;
        scanf("%s", s);
        sscanf(s, "theta=%lf", &theta);
        for(int i = 0; i < n; ++i) {
            printf("(%.2lf,%.2lf)\n", x[i] * cos(theta) + y[i] * sin(theta), y[i] * cos(theta) - x[i] * sin(theta));
        }
    }
}