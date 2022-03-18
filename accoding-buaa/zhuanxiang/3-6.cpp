// https://accoding.buaa.edu.cn/contest-ng/index.html#/714/problems

#include<stdio.h>
#include<string.h>

int main() {
    char s[20];
    while(scanf("%s", s)!=EOF) {
        int temp;
        char tag;
        sscanf(s, "<%d><%c>", &temp, &tag);
        double convertTemp;
        char convertTag;
        if(tag == 'C') {
            convertTemp = temp * 9.0 / 5.0 + 32;
            convertTag = 'F';
        }
        else {
            convertTemp = (temp - 32) * 5.0 / 9.0;
            convertTag = 'C';
        }
        printf("<%d><%c>=<%.1f><%c>\n", temp, tag, convertTemp, convertTag);
    }
}