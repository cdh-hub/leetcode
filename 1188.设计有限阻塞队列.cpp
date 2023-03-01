/*
 * @lc app=leetcode.cn id=1188 lang=cpp
 *
 * [1188] 设计有限阻塞队列
 */

// @lc code=start
#include <semaphore.h>
class BoundedBlockingQueue {
private:
    queue<int> q;
    sem_t t1, t2;
public:
    BoundedBlockingQueue(int capacity) {
        sem_init(&t1, 0, capacity);
        sem_init(&t2, 0, 0);
    }
    
    void enqueue(int element) {
        sem_wait(&t1);
        q.push(element);
        sem_post(&t2);
    }
    
    int dequeue() {
        sem_wait(&t2);
        int ans = q.front();
        q.pop();
        sem_post(&t1);
        return ans;
    }
    
    int size() {
        return q.size();
    }
};
// @lc code=end

