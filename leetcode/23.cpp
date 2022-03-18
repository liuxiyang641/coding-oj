// https://leetcode.com/problems/merge-k-sorted-lists/
// 同时归并排序多个list，个人使用了归并排序，但是根据LeetCode上的写法，使用优先队列更快

#include<vector>
#include<stdio.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = NULL;
        if(lists.size()==0) {
            return NULL;
        }
        res = lists[0];
        for(int i = 1; i < lists.size(); ++i) {
            res = merge(res, lists[i]);
        }
        return res;
    }
    // 归并排序
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* reshead = NULL, *restpr = NULL;
        ListNode* tpr1 = l1, *tpr2 = l2;
        int minVal; // 记录最小值
        ListNode* minNext = NULL; // 记录最小值的地址
        while(tpr1 != NULL && tpr2 != NULL) {
            if(tpr1->val < tpr2->val) {
                minVal = tpr1->val;
                minNext = tpr1;
                tpr1 = tpr1->next;
            }
            else {
                minVal = tpr2->val;
                minNext = tpr2;
                tpr2 = tpr2->next;
            }
            if(reshead != NULL) {
                restpr->next = minNext;
                restpr = restpr->next;
            }
            else {
                reshead = minNext;
                restpr = reshead;
            }
        }
        while(tpr1 != NULL) {
            minVal = tpr1->val;
            if(reshead != NULL) {
                restpr->next = tpr1;
                restpr = restpr->next;
            }
            else {
                reshead = tpr1; 
                restpr = reshead;
            }
            tpr1 = tpr1->next;
        }
        while(tpr2 != NULL) {
            minVal = tpr2->val;
            if(reshead != NULL) {
                restpr->next = tpr2;
                restpr = restpr->next;
            }
            else {
                reshead = tpr2;
                restpr = reshead;
            }
            tpr2 = tpr2->next;
        }
        restpr = NULL;
        delete restpr;
        return reshead;
    }
};


