// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem146.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
typedef struct LinkedList ll;
struct LinkedList {
    ll* next;
    ll* prev;
    int key, value;
};

class LRUCache {
private:
    ll* head;
    ll* tail;
    int size;
    unordered_map<int, ll*> map;
    int capacity; 
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new ll;
        tail = new ll;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (map.count(key)) {
            map[key]->prev->next = map[key]->next;
            map[key]->next->prev = map[key]->prev;
            map[key]->prev = head;
            map[key]->next = head->next;
            head->next = map[key];
            map[key]->next->prev = map[key];
            return map[key]->value;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {    
        if (map.count(key)) {
            map[key]->value = value;
            map[key]->prev->next = map[key]->next;
            map[key]->next->prev = map[key]->prev;
            map[key]->prev = head;
            map[key]->next = head->next;
            head->next = map[key];
            map[key]->next->prev = map[key];
        }
        else {
            map[key] = new ll;
            map[key]->key = key;
            map[key]->value = value;
            map[key]->prev = head;
            map[key]->next = head->next;
            head->next = map[key];
            map[key]->next->prev = map[key];
            size++;
            if (size > capacity) {
                ll* tmp = tail->prev;
                map.erase(tmp->key);
                tail->prev = tail->prev->prev;
                tail->prev->next = tail;
                delete tmp;
                size--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

