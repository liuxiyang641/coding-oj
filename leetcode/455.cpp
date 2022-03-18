// https://leetcode.com/problems/assign-cookies/
// 贪心算法

#include <iostream>
#include <vector>
#include<stdlib.h>
#include <algorithm>
using namespace std;

// 下面这个是leetcode书上的写法
// sort(array, array+end, cmp);
class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cookie_id = 0, child_id = 0;
        while(cookie_id<s.size() && child_id < g.size())
        {
            if(s[cookie_id]>=g[child_id]) ++child_id;
            ++cookie_id;
        } 
        return child_id;
    }
};

int main(int argc, char** argv)
{
    while(true)
    {
        Solution solution;
        vector<int> g;
        vector<int> s;
        int input;
        while(cin>>input)
        {
            g.push_back(input);
            if(cin.get() == '\n')
            {
                break;
            }
        }
        while(cin>>input)
        {
            s.push_back(input);
            if(cin.get() == '\n')
            {
                break;
            }
        }
        int out = solution.findContentChildren(g, s);
        cout<<out<<endl;
    }
    return 0;
}


// 下面这个是c语言的写法
// qsort(array, arraySize, sizeof(element), int cmpfunc (const void * a, const void * b))
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    if(sSize == 0 || gSize == 0) {
        return 0;
    }
    qsort(s, sSize, sizeof(int), cmpfunc);
    qsort(g, gSize, sizeof(int), cmpfunc);
    int ans = 0;
    int j = 0;
    for(int i = 0; i < gSize;) {
        if(s[j] >= g[i]) {
            j++;
            ans++;
            i++;
        }
        else {
            j++;
        }
        if(j == sSize) {
            return ans;
        }
    }
    return ans;
}