// https://leetcode.com/problems/lru-cache/
// 使用c语言实现的LRU算法
// 核心在于：使用一个队列保持最近使用的节点，使用key直接索引到对应的在队列中的位置地址还有对应的值
// 最容易出错的是，队列实现的时候涉及到头尾节点的变化，要小心头尾节点移动出错

#include<algorithm>
using namespace std;


struct queue {
    struct queue* next;
    struct queue* prev;
    int key;
};

typedef struct {
    int data[10001];
    struct queue* head, *end; // LRU队列，队头就是最近使用的，队尾是最长时间未使用的
    struct queue* keyToAddress[10001]; // 根据key，快速找到在LRU队列中的位置
    int size;
    int capacity;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* root = (LRUCache*)malloc(sizeof(LRUCache));
    root->capacity = capacity;
    root->head = (struct queue*)malloc(sizeof(struct queue));
    root->head->next = root->head->prev = NULL;
    root->end = root->head;
    for(int i = 0; i < 10001; ++i) {
        root->data[i] = -1;
    }
    root->size = 0;
    return root;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if(obj->data[key] == -1) {
        return -1;
    }
    else {
        struct queue* tmpNode = obj->keyToAddress[key];
        // 从队列中移除
        tmpNode->prev->next = tmpNode->next;
        if(tmpNode->next) {
            tmpNode->next->prev = tmpNode->prev;
        }
        else {
            // 如果当前节点刚好是end，并且前面还有候选的节点而不是头结点
            // 如果当前节点刚好是end并且队列中只有一个节点，尾结点也不需要移动
            if(tmpNode->prev != obj->head)
                obj->end = tmpNode->prev;
        }
        // 插入到队列头部
        tmpNode->prev = obj->head;
        tmpNode->next = obj->head->next;
        if(obj->head->next) {
            obj->head->next->prev = tmpNode;
        }
        obj->head->next = tmpNode;
        return obj->data[key];
    }
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if(lRUCacheGet(obj, key) == -1) {
        // 如果没有对于的key-val对
        obj->data[key] = value;
        // 更新LRU queue
        struct queue* tmpNode = (struct queue*)malloc(sizeof(struct queue));
        tmpNode->key = key;
        tmpNode->next = obj->head->next;
        tmpNode->prev = obj->head;
        if(obj->head->next) {
            obj->head->next->prev = tmpNode;
        }
        obj->head->next = tmpNode;
        if(obj->size == 0) {
            obj->end = tmpNode;
        }
        obj->keyToAddress[tmpNode->key] = tmpNode; // 根据key，快速找到在LRU队列中的位置
        // 判断是否超出新的界限
        obj->size++;
        if(obj->size > obj->capacity) {
            // 开始删除尾端的key-val
            struct queue* tmpNode = obj->end;
            obj->end = obj->end->prev;
            obj->data[tmpNode->key] = -1;
            obj->keyToAddress[tmpNode->key] = NULL;
            free(tmpNode);
            obj->end->next = NULL;
            obj->size--;
        }
    }
    else {
        obj->data[key] = value;
        struct queue* tmpNode = obj->keyToAddress[key];
        // 从队列中移除对应的节点
        tmpNode->prev->next = tmpNode->next;
        if(tmpNode->next) {
            tmpNode->next->prev = tmpNode->prev;
        }
        else {
            // 如果当前节点刚好是end，并且前面还有候选的节点而不是头结点
            if(tmpNode->prev != obj->head)
                obj->end = tmpNode->prev;
        }
        // 将对应节点放到队列头部
        tmpNode->prev = obj->head;
        tmpNode->next = obj->head->next;
        if(obj->head->next) {
            obj->head->next->prev = tmpNode;
        }
        obj->head->next = tmpNode;
    }
}

void lRUCacheFree(LRUCache* obj) {
    free(obj);
}