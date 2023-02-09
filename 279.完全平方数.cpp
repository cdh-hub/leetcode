/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> ps;
        for (int i = 1; i <= 100; i++) ps.push_back(i*i);
        int dp[n+1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            for (int j = 0; j < ps.size() && ps[j] <= i; j++) {
                dp[i] = min(dp[i], dp[i-ps[j]] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

