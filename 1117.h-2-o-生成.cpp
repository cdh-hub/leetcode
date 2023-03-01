/*
 * @lc app=leetcode.cn id=1117 lang=cpp
 *
 * [1117] H2O 生成
 */

// @lc code=start
class H2O {
private:
    int h, o;
    mutex m;
    condition_variable cv;
public:
    H2O(): h(0), o(0) {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this]{return h < 2;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++h;
        if (h == 2 && o == 1) {
            h = 0; o = 0; cv.notify_all();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this]{return o < 1;});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        ++o;
        if (h == 2 && o == 1) {
            h = 0; o = 0; cv.notify_all();
        }
    }
};
// @lc code=end

