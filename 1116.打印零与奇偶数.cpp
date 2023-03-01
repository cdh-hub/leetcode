/*
 * @lc app=leetcode.cn id=1116 lang=cpp
 *
 * [1116] 打印零与奇偶数
 */

// @lc code=start
class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv0, cv1, cv2;
    bool z, e, o;
public:
    ZeroEvenOdd(int n): n(n), z(true), e(false), o(false) {
        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            {
                unique_lock<mutex> l(m);
                cv0.wait(l, [this]{return z;});
                printNumber(0);
                z = false;
                if (i & 1) o = true;
                else e = true;
            }
            cv1.notify_one();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            {
                unique_lock<mutex> l(m);
                cv1.wait(l, [this]{return e;});
                printNumber(i);
                e = false;
                z = true;
            }
            cv0.notify_one();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            {
                unique_lock<mutex> l(m);
                cv1.wait(l, [this]{return o;});
                printNumber(i);
                o = false;
                z = true;
            }
            cv0.notify_one();
        }
    }
};
// @lc code=end

