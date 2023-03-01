/*
 * @lc app=leetcode.cn id=1226 lang=cpp
 *
 * [1226] 哲学家进餐
 */

// @lc code=start
class DiningPhilosophers {
private:
    mutex m[5];
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        if (philosopher & 1) {
            m[philosopher].lock();
            m[(philosopher+1)%5].lock();
        }
        else {
            m[(philosopher+1)%5].lock();
            m[philosopher].lock();
        }
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        m[philosopher].unlock();
        m[(philosopher+1)%5].unlock();
    }
};
// @lc code=end

