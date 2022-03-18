// https://leetcode.com/problems/different-ways-to-add-parentheses/
// 下面的代码是直接来自于书上的内容
// 给表达式加任意的括号，对于不同的操作符来说，它左右两边一定最后会有一个用来计算的结果，任意操作符的两端都看作是不同的表达式，经过
// 加括号有不同的结果，可以与该操作符一起有不同的操作结果


#include<vector>
#include<string>
using namespace std;

class Solution
{
public:
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> ways;
        for (int i = 0; i < input.length(); i++)
        {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (const int &l : left)
                {
                    for (const int &r : right)
                    {
                        switch (c)
                        {
                        case '+':
                            ways.push_back(l + r);
                            break;
                        case '-':
                            ways.push_back(l - r);
                            break;
                        case '*':
                            ways.push_back(l * r);
                            break;
                        }
                    }
                }
            }
        }
        if (ways.empty())
            ways.push_back(stoi(input));
        return ways;
    }
};