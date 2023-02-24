/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][2];
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = max(dp[i-1][0] + prices[i-1] - prices[i-2], dp[i-2][1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i-1] - prices[i-2]);
        }
        return dp[n][1];
    }
};
// @lc code=end

