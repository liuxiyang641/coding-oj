#include <iostream>
// https://leetcode.com/problems/merge-sorted-array/


#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int id1 = m - 1, id2 = n - 1;
        int put_id = m + n -1;
        while(id1 >= 0 && id2 >= 0)
        {
            if (nums1[id1] >= nums2[id2])
            {
                nums1[put_id]=nums1[id1];
                --put_id;
                --id1;
            }
            else if (nums1[id1] < nums2[id2])
            {
                nums1[put_id]=nums2[id2];
                --put_id;
                --id2;
            }
        }
        while (id2 >= 0)
        {
            nums1[put_id]=nums2[id2];
            --put_id;
            --id2;
        }
    }
};

int main(int argc, char** argv)
{
    
}