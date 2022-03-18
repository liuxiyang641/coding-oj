// https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head){
    struct ListNode* fast = head, *slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // 如果是奇数个数，slow在中心结点，如果是偶数个数，slow在中心分界线左结点
    // 从slow->next开始反转链表
    struct ListNode* secondPartPtr = slow->next;
    struct ListNode* secondPartDummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    secondPartDummy->next = NULL;
    while(secondPartPtr) {
        struct ListNode* tmpPtr = secondPartPtr->next;
        secondPartPtr->next = secondPartDummy->next;
        secondPartDummy->next = secondPartPtr;
        secondPartPtr = tmpPtr;
    }
    // 比较head开始的前半部分和slow->next开始的部分是否对称
    slow = secondPartDummy->next;
    while(slow) {
        if(head->val != slow->val) {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}

