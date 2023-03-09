/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[n+1];
        dp[0] = 0;
        int tag = 1;
        for (int i = 1; i <= n; i++) {
            if (obstacleGrid[0][i-1]) tag = 0;
            dp[i] = tag;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[j] = obstacleGrid[i][j-1] ? 0 : dp[j-1] + dp[j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

