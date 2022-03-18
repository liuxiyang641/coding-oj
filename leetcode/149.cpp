// https://leetcode.com/problems/max-points-on-a-line/
// 判断多个点，最多有几个点在同一直线上
// 思路：对于每个点i，假设有一条线经过点i，那么点i和其它点之间的斜率的最多相同的个数，就是过点i的直线能经过的最多点。遍历所有点，选择最大点数

#include<vector>
#include<set>
#include<unordered_map>
#include<math.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 2) {
            return 1;
        }
        int maxAns = 2;
        for(int i = 0; i < points.size(); ++i) {
            unordered_map<double, int> slotCount;
            for(int j = 0; j < points.size(); ++j) {
                if(i != j) {
                    int y = points[i][1] - points[j][1];
                    int x = points[i][0] - points[j][0];
                    double slot = (y * 1.0) / x;
                    unordered_map<double, int>::iterator it = slotCount.find(slot);
                    if(it != slotCount.end()) {
                        it->second++;
                        maxAns = maxAns > it->second ? maxAns : it->second;
                    }
                    else {
                        slotCount.insert(make_pair(slot, 2));
                    }
                }
            }
        }
        return maxAns;
    }
};