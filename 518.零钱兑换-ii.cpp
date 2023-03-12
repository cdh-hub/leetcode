/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int dp[amount+1];
        dp[0] = 1;
        for (int i = 1; i <= amount; i++) dp[i] = 0;
        for (int j = 0; j < (int)coins.size(); j++) {
            for (int i = coins[j]; i <= amount; i++) {
                dp[i] += dp[i-coins[j]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

