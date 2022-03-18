// https://leetcode.com/problems/reverse-linked-list/
// 反转链表，把旧链表的每一个数逆序输出。只需要把旧链表的每一个元素不断插入到头部即可

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

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* dummyNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyNode->next = NULL;
    while(head != NULL) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = head->val;
        newNode->next = dummyNode->next;
        dummyNode->next = newNode;
        head = head->next;
    }
    return dummyNode->next;
}