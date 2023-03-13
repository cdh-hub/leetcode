/*
 * @lc app=leetcode.cn id=2571 lang=cpp
 *
 * [2571] 将整数减少到零需要的最少操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while (n > 0) {
            while ((n & 1) == 0) {
                n >>= 1;
            }
            if ((n >> 1) & 1) ++n;
            else --n;
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

