#include<stdio.h>
#include<string.h>

double getWeight(char c) {
    switch(c) {
        case 'C':
            return 12.01;
        case 'H':
            return 1.008;
        case 'O':
            return 16.00;
        case 'N':
            return 14.01;
    }
}

int main() {
    char s[101];
    while(~scanf("%s", s)) {
        int len = strlen(s);
        int i = 0;
        double sum = 0;
        while(i < len) {
            char c = s[i++];
            // 开始读入数字
            int count = 0;
            while(i < len && s[i] >= '0' && s[i] <= '9') {
                count = count * 10 + s[i] - '0';
                i++;
            }
            if(count == 0) {
                count = 1;
            }
            sum += getWeight(c) * count;
        }
        printf("%.3lf\n", sum);
    }
}