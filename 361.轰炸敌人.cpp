/*
 * @lc app=leetcode.cn id=361 lang=cpp
 *
 * [361] 轰炸敌人
 */

// @lc code=start
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m][n][4];
        int begin[4][2] = {{0,0},{0,n-1},{0,0},{m-1,0}};
        int diff[4][2] = {{1,1},{1,-1},{1,1},{-1,1}};
        int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
        for (int k = 0; k < 4; k++) {
            for (int i = begin[k][0]; i != m-1-begin[k][0]+diff[k][0]; i += diff[k][0]) {
                for (int j = begin[k][1]; j != n-1-begin[k][1]+diff[k][1]; j += diff[k][1]) {
                    int ii = i + dir[k][0], jj = j + dir[k][1];
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n || grid[ii][jj] == 'W') dp[i][j][k] = 0;
                    else dp[i][j][k] = dp[ii][jj][k] + (grid[ii][jj] == 'E' ? 1 : 0);
                 //   cout << dp[i][j][k] << ", ";
                }
               // cout << endl;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    ans = max(ans, dp[i][j][0]+dp[i][j][1]+dp[i][j][2]+dp[i][j][3]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

