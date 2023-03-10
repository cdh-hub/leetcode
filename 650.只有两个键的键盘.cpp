/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return minSteps(n/i) + i;
        }
        return n;
    }
};
// @lc code=end

