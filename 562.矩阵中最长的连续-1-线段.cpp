/*
 * @lc app=leetcode.cn id=562 lang=cpp
 *
 * [562] 矩阵中最长的连续1线段
 */

// @lc code=start
class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int dp[m+2][n+2][4];
        for (int i = 0; i <= m; i++) 
            for (int k = 0; k < 4; k++) {
                dp[i][0][k] = 0;
                dp[i][n+1][k] = 0;
            }
        for (int j = 0; j <= n; j++)
            for (int k = 0; k < 4; k++) {
                dp[0][j][k] = 0;
                dp[m+1][j][k] = 0;
            }
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j][0] = mat[i-1][j-1] ? dp[i-1][j][0]+1 : 0;
                dp[i][j][1] = mat[i-1][j-1] ? dp[i][j-1][1]+1 : 0;
                dp[i][j][2] = mat[i-1][j-1] ? dp[i-1][j-1][2]+1 : 0;
                dp[i][j][3] = mat[i-1][j-1] ? dp[i-1][j+1][3]+1 : 0;
                ans = max(ans, dp[i][j][0]);
                ans = max(ans, dp[i][j][1]);
                ans = max(ans, dp[i][j][2]);
                ans = max(ans, dp[i][j][3]);
            }
        }
        return ans;
    }
};
// @lc code=end

