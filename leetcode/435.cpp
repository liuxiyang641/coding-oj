// https://leetcode.com/problems/non-overlapping-intervals/
// 贪心算法

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), 
        [](vector<int>& a, vector<int>& b) -> bool 
        {
            return a[1] < b[1];
        });
        int era_cnt = 0, pre_end = intervals[0][1];
        for(int i = 1; i<intervals.size(); ++i)
        {
            if (intervals[i][0]<pre_end)
            {
                // overlapping, remove
                ++era_cnt;
            }
            else
            {
                // preserving
                pre_end = intervals[i][1];
            }
        }
        return era_cnt;
    }
};

int main(int argc, char** argv)
{
    while(true)
    {
        int input1, input2;
        vector<vector<int>> intervals;
        while(cin>>input1>>input2)
        {
            vector<int> tmp = {input1, input2};
            intervals.push_back(tmp);
            if(cin.get()=='\n') break;
        }
        Solution solution;
        cout<<solution.eraseOverlapIntervals(intervals)<<endl;
    }
    return 0;
}

// 按照线段右端点排序
// 注意在qsort中，传入的参数是数组元素的指针，这里数组元素是int*，所以a和b应该是int**类型的指针。*a表示是实际的以为数字指针元素，然后*a[1]就是
// 对应的元素

int cmp(const void* a, const void* b) {
    return (*(int**)a)[1] - (*(int**)b)[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int preRight = intervals[0][1];
    int removeNum = 0;
    for(int i = 1; i < intervalsSize; ++i) {
        if(intervals[i][0] < preRight) {
            removeNum++;
        }
        else {
            preRight = intervals[i][1];
        }
    }
    return removeNum;
}