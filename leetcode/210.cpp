// https://leetcode.com/problems/course-schedule-ii/
// 拓扑排序，本质上还是使用DFS实现的遍历

#include<algorithm>
using namespace std;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    // int parent[2001];
    int child[2001];
    int parentLen;
    int childLen;
} Node;

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * numCourses);
    *returnSize = 0;
    // 注意动态分配数组不能使用int a[100]的静态方法
    Node* graph = (Node*)malloc(sizeof(Node) * numCourses);
    bool* isRoot = (bool*)malloc(sizeof(bool) * numCourses);
    for(int i = 0; i < numCourses; ++i) {
        isRoot[i] = true;
        graph[i].parentLen = graph[i].childLen = 0;
    }
    for(int i = 0; i < prerequisitesSize; ++i) {
        int b = prerequisites[i][0];
        int a = prerequisites[i][1];
        isRoot[b] = false;
        graph[a].child[graph[a].childLen++] = b;
        graph[b].parentLen++;
    }
    // queue保留所有的起点，即没有parent的节点
    int* queue = (int*)malloc(sizeof(int) * numCourses);
    int len = 0;
    // 寻找所有的起始节点
    for(int i = 0; i < numCourses; ++i) {
        if(isRoot[i]) {
            queue[len++] = i;
        }
    }
    // 开始DFS遍历
    while(len) {
        int topNode = queue[--len];
        ans[*returnSize] = topNode;
        *returnSize += 1;
        for(int i = 0; i < graph[topNode].childLen; ++i) {
            int nei = graph[topNode].child[i];
            // 消除邻居节点的一条边
            graph[nei].parentLen--;
            // 如果邻居节点变为了新的起点
            if(graph[nei].parentLen == 0) {
                queue[len++] = nei;
            }
        }
    }
    // 如果能够访问到所有的节点
    if(*returnSize == numCourses) {
        return ans;
    }
    else {
        // 如果图中存在环，就无法访问所有的节点
        ans = NULL;
        *returnSize = 0;
        return ans;
    }
}