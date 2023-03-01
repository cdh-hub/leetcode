/*
 * @lc app=leetcode.cn id=1115 lang=cpp
 *
 * [1115] 交替打印 FooBar
 */

// @lc code=start
class FooBar {
private:
    int n;
    mutex mtx1, mtx2;
public:
    FooBar(int n) {
        this->n = n;
        mtx2.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            mtx1.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            mtx2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            mtx2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            mtx1.unlock();
        }
    }
};
// @lc code=end

