/*
 * @lc app=leetcode.cn id=1195 lang=cpp
 *
 * [1195] 交替打印字符串
 */

// @lc code=start
class FizzBuzz {
private:
    int n;
    int a;
    condition_variable cv;
    mutex m;
public:
    FizzBuzz(int n) {
        this->n = n;
        a = 0;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i = 3; i <= n; i += 3) {
            if (i % 5 == 0) continue;
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this, i] {return a == i - 1;});
            printFizz();
            ++a;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i = 5; i <= n; i += 5) {
            if (i % 3 == 0) continue;
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this, i] {return a == i - 1;});
            printBuzz();
            ++a;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i = 15; i <= n; i += 15) {
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this, i] {return a == i - 1;});
            printFizzBuzz();
            ++a;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 || i % 5 == 0) continue;
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this, i] {return a == i - 1;});
            printNumber(i);
            ++a;
            cv.notify_all();
        }
    }
};
// @lc code=end

