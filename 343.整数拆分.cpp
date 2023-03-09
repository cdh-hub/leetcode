/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        dp[1] = 1;
        if (n == 2) return 1;
        dp[2] = 2;
        if (n == 3) return 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++) {
            dp[i] = max(dp[i-2]*2, dp[i-3]*3);
        }
        return dp[n];
    }
};
// @lc code=end

