/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
private:
    int f[31] = {0};
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (f[n] != 0) return f[n];
        else f[n] = fib(n-1) + fib(n-2);
        return f[n];
    }
};
// @lc code=end

