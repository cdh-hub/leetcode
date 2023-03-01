/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */

// @lc code=start
class Foo {
    mutex mtx1, mtx2;
public:
    Foo() {
        mtx1.lock();
        mtx2.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        mtx1.unlock();
    }

    void second(function<void()> printSecond) {
        mtx1.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        mtx2.unlock();
    }

    void third(function<void()> printThird) {
        mtx2.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
// @lc code=end

