// https://leetcode.com/problems/linked-list-random-node/
// 连续输入，不知事先所有数据长度的随机采样，使用水库算法，对于输入的第i个数据，是否采用该数据的概率为1/i，最后结果和1/n的概率是等价的。

#include<algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct {
    struct ListNode* data;
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    Solution* solu = (Solution*)malloc(sizeof(Solution));
    solu->data = head;
    return solu;
}

int solutionGetRandom(Solution* obj) {
    int randVal = 0;
    struct ListNode* node = obj->data;
    int count = 1;
    while(node!=NULL) {
        // rand() % count 产生0-count-1的数字，等于任一0-count-1的数字概率都是相等的，
        // 但是只有0是在所有count中都存在，设置为其它数字可能导致该数字不再0-count-1的范围
        if((rand() % count) == 0) {
            randVal = node->val;
        }
        count++;
        node = node->next;
    }
    return randVal;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/