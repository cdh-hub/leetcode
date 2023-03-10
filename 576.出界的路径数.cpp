/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 */

// @lc code=start
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int MOD = 1000000007;
        int dp[m][n][maxMove+1];
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) dp[i][j][0] = 0;
        for (int k = 1; k <= maxMove; k++) {
            for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
                dp[i][j][k] = 0;
                for (int d = 0; d < 4; d++) {
                    int ii = i+dir[d][0], jj = j+dir[d][1];
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n) dp[i][j][k] = (dp[i][j][k] + 1) % MOD;
                    else dp[i][j][k] = (dp[i][j][k] + dp[ii][jj][k-1]) % MOD;
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
};
// @lc code=end

