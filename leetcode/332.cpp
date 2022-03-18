// https://leetcode.com/problems/reconstruct-itinerary/
// 一个有向图，从固定起点出发能够遍历所有节点

#include <vector>
#include <string>
#include <set>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        vector<string> ans;
        if (tickets.empty())
        {
            return ans;
        }
        unordered_map<string, multiset<string>> hash;
        for (const auto &ticket : tickets)
        {
            hash[ticket[0]].insert(ticket[1]);
        }
        stack<string> s;
        s.push("JFK");
        while (!s.empty())
        {
            string next = s.top();
            // 走到了终结点
            if (hash[next].empty())
            {
                ans.push_back(next);
                s.pop();
            }
            else
            {
                s.push(*hash[next].begin());
                hash[next].erase(hash[next].begin());
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};