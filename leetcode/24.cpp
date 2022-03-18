// https://leetcode.com/problems/swap-nodes-in-pairs/
// 链表相邻元素互换，使用了递归的写法


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

struct ListNode* swapPairs(struct ListNode* head) {
    if(!head) {
        return NULL;
    }
    struct ListNode* oldHead = head;
    struct ListNode* newHead = head->next;
    if(!newHead) {
        return head;
    }
    oldHead->next = swapPairs(newHead->next);
    newHead->next = oldHead;
    return newHead;
}