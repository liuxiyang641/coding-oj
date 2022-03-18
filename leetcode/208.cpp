// https://leetcode.com/problems/implement-trie-prefix-tree/
// 构造一棵字典树，实现插入，查询等操作
// 重点在于字典树的每个节点包括一个指向26个字母的链表数组，根结点是一个没有任何实际含义的空节点

#include<algorithm>
#include<string.h>
using namespace std;

typedef struct {
    int count;
    char s;
     Trie* next [26];
} Trie;

Trie* createNewNode(char s) {
    Trie* root = (Trie*)malloc(sizeof(Trie));
    root->count = 0;
    root->s = s;
    for(int i = 0; i < 26; ++i) {
        root->next[i] = NULL;
    }
    return root;
}

Trie* trieCreate() {
    return createNewNode('\0');
}

void trieInsert(Trie* obj, char * word) {
    int len = strlen(word);
    for(int i = 0; i < len; ++i) {
        if(!obj->next[word[i] - 'a']) {
            obj->next[word[i] - 'a'] = createNewNode(word[i]);
        }
        obj = obj->next[word[i] - 'a'];
    }
    obj->count = 1;
    return;
}

bool trieSearch(Trie* obj, char * word) {
    int len = strlen(word);
    for(int i = 0; i < len; ++i) {
        if(!obj->next[word[i] - 'a']) {
            return false;
        }
        obj = obj->next[word[i] - 'a'];
    }
    if(obj->count != 1) {
        return false;
    }
    return true;
}

bool trieStartsWith(Trie* obj, char * prefix) {
    int len = strlen(prefix);
    for(int i = 0; i < len; ++i) {
        if(!obj->next[prefix[i] - 'a']) {
            return false;
        }
        obj = obj->next[prefix[i] - 'a'];
    }
    return true;
}

void trieFree(Trie* obj) {
    free(obj);
}