// https://leetcode.com/problems/minimum-window-substring/
// 滑动窗口

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

char * minWindow(char * s, char * t)
{
    bool flag[123] = {false};
    int count[123] = {0};
    int target_length = strlen(t);
    int source_length = strlen(s);
    // 统计目标字符串
    for(int i=0;i<target_length;++i)
    {
        flag[t[i]] = true;
        count[t[i]]++;
    }
    int win_l = 0;
    int occur_count = 0;
    int min_size = source_length + 1;
    int min_win_l = 0;
    for(int i = 0; i < source_length; ++i)
    {
        if(flag[s[i]])
        {
            if(count[s[i]] > 0)
            {
                // 在目标字符串中，并且不是冗余的字符
                ++occur_count;
            }
            // 记录出现了对应的冗余字符
            --count[s[i]];
            while (occur_count == target_length)
            {
                if(i - win_l + 1 < min_size)
                {
                    // 如果找到的新字符串长度更小
                    min_win_l = win_l;
                    min_size = i - win_l + 1;
                }
                if (flag[s[win_l]])
                {
                    if (count[s[win_l]] < 0)
                    {
                        // 存在冗余字符，左边框可以向右移动
                        ++count[s[win_l]];
                        ++win_l;
                    }
                    else break;
                }
                else
                {
                    // 非目标字符，左边框向右移动
                    ++win_l;
                }  
            }
        }
    }
    if (min_size == source_length + 1) return "";
    else 
    {
        char * output= (char *)malloc((min_size+1) * sizeof(char));
        *output = '\0';
        strncat(output, s+min_win_l, min_size);
        return output;
    }
}

int main(int argc, char** argv)
{
    while(true)
    {
        char * s = "ADOBECODEBANC";
        char * t = "ABC";
        char * o = minWindow(s, t);
        int a =1;
    }
    
    return 0;
}