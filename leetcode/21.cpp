// https://leetcode.com/problems/merge-two-sorted-lists/
// 链表形式的归并排序

#include<algorithm>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head = dummy;
    dummy->next = NULL;
    while(list1 && list2) {
        struct ListNode* tmpNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmpNode->next = NULL;
        if(list1->val < list2->val) {
            tmpNode->val = list1->val;
            list1 = list1->next;
        }
        else {
            tmpNode->val = list2->val;
            list2 = list2->next;
        }
        head->next = tmpNode;
        head = head->next;
    }
    struct ListNode* resNode = NULL;
    if(list1 != NULL) {
        resNode = list1;
    }
    else if(list2 != NULL) {
        resNode = list2;
    }
    while(resNode) {
        struct ListNode* tmpNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmpNode->next = NULL;
        tmpNode->val = resNode->val;
        resNode = resNode->next;
        head->next = tmpNode;
        head = head->next;
    }
    return dummy->next;
}