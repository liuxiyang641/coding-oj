// https://leetcode.com/problems/partition-labels/
// 贪心算法，统计最多重复的区间数量
// 贪心的核心在于，从当前按照右端点拍好序的区间出发，寻找后面左端点小于当前右端点的最远区间

#include<algorithm>
#include<string.h>
using namespace std;

int cmp(const void* a, const void* b) {
    // printf("%d ", (*(int**)a)[1]);
    return (*(int**)a)[1] - (*(int**)b)[1];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * s, int* returnSize) {
    int len = strlen(s);
    int** charSection = (int**)malloc(sizeof(int*) * 27);
    for(int i = 0; i < 27; ++i) {
        charSection[i] = (int*)malloc(sizeof(int) * 2);
        charSection[i][0] = -1;
        charSection[i][1] = -1;
    }
    // 统计各个字符出现的区间
    for(int i = 0; i < len; ++i) {
        if(charSection[s[i] - 'a'][0] == -1) {
            charSection[s[i] - 'a'][0] = i;
            charSection[s[i] - 'a'][1] = i;
        }
        else {
            charSection[s[i] - 'a'][1] = i;
        }
    }
    int* ans = (int*)malloc(sizeof(int) * 27);
    *returnSize = 0;
    qsort(charSection, 27, sizeof(int*), cmp);
    // 开始贪心
    int preRight = len;
    for(int i = 0; i < 27;) {
        if(charSection[i][0] != -1) {
            int nextI = i + 1;
            preRight = charSection[i][1];
            // 寻找之后有最多的重复区间数量
            for(int j = i + 1; j < 27; ++j) {
                // 如果和前面的重叠
                if(charSection[j][0] < preRight) {
                    preRight = charSection[j][1];
                    nextI = j + 1;
                }
            }
            i = nextI;
            ans[*returnSize] = preRight + 1;
            *returnSize += 1;
        }
        else {
            ++i;
        }
    }
    // 计算长度
    for(int i = *returnSize - 1; i >= 1; --i) {
        ans[i] -=  ans[i - 1];
    }
    return ans;
}