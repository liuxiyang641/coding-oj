// https://leetcode.com/problems/intersection-of-two-linked-lists/
// 判断两个链表是否相交，使用两个指针从各自头结点出发，走到尾端时就跑到另外一个链表的节点继续走，因为总路程一样，所以最后一定会相遇在相交点

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

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode * p1 = headA, *p2 = headB;
    // 如果不想交，会得到NULL 
    while (p1 != p2)
    {
        p1 = p1 ? p1->next : headB;
        p2 = p2 ? p2->next : headA;
    }
    return p1;
}