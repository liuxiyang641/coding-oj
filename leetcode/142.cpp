// https://leetcode.com/problems/linked-list-cycle-ii/
// 快慢指针，快慢指针相遇能够判定是链表中存在环；然后将快指针移动到链表首位，保持和慢指针一样的速度，继续移动，第二次相遇就是环开始的点

#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast = head,  * slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                // cycle
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

