/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i-1][0];
        }
        for (int i = 1; i < n; i++) {
            grid[0][i] += grid[0][i-1];
            for (int j = 1; j < m; j++) {
                grid[j][i] += min(grid[j-1][i], grid[j][i-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
// @lc code=end

