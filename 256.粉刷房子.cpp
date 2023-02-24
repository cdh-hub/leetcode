/*
 * @lc app=leetcode.cn id=256 lang=cpp
 *
 * [256] 粉刷房子
 */

// @lc code=start
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int dp[n+1][3];
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i+1][j] = min(dp[i][(j+1)%3], dp[i][(j+2)%3]) + costs[i][j];
            }
        }
        return min(min(dp[n][0], dp[n][1]), dp[n][2]);
    }
};
// @lc code=end

