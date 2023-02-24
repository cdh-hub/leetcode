/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = -fee;
        dp[0][1] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0] + prices[i] - prices[i-1], dp[i-1][1] - fee);
            dp[i][1] = max(dp[i-1][0] + prices[i] - prices[i-1], dp[i-1][1]);
        }
        return dp[n-1][1];
    }
};
// @lc code=end

