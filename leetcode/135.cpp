// https://leetcode.com/problems/candy/
// 贪心算法，给排好队的孩子分蛋糕，得分高的小孩要比两边的小孩有更多的蛋糕，为了解决比两边的邻居多这个问题，从左到右，保证比左边邻居多，然后从
// 右到左，保证比右边邻居多即可

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Soulution
{
    public:
       int candy(vector<int>& ratings)
       {
           if (ratings.size() == 1)
           {
               return 1;
           }
           vector<int> candy_cnt(ratings.size(), 1);
           for (int i = 1; i < ratings.size(); i++)
           {
               if(ratings[i] > ratings[i-1])
               {
                   candy_cnt[i] = candy_cnt[i-1] + 1;
               }
           }
           for (int i = ratings.size() - 1; i > 0; i--)
           {
               if(ratings[i-1] > ratings[i] && candy_cnt[i-1] <= candy_cnt[i])
               {
                   candy_cnt[i-1] = candy_cnt[i] + 1;
               }
           }
           return accumulate(candy_cnt.begin(), candy_cnt.end(), 0);
       } 
};

int main(int argc, char** argv)
{
    while(true)
    {
        int input;
        vector<int> kid_ratings;
        Soulution soulution;
        while(cin>>input)
        {
            kid_ratings.push_back(input);
            if(cin.get()=='\n') break;
        }
        int out = soulution.candy(kid_ratings);
        cout<<out<<endl;
    }
    return 0;
}




int candy(int* ratings, int ratingsSize) {
    int* c = (int*)malloc(sizeof(int) * ratingsSize);
    c[0] = 1;
    for(int i = 1; i < ratingsSize; ++i) {
        if(ratings[i] <= ratings[i - 1]) {
            c[i] = 1;
        }
        else {
            c[i] = c[i - 1] + 1;
        }
    }
    for(int i = ratingsSize - 2; i >= 0; --i) {
        if(ratings[i] > ratings[i + 1] && c[i] <= c[i + 1]) {
             c[i] = c[i + 1] + 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < ratingsSize; ++i) {
        ans += c[i];
    }
    return ans;
}