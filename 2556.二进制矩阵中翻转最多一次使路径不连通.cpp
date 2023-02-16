/*
 * @lc app=leetcode.cn id=2556 lang=cpp
 *
 * [2556] 二进制矩阵中翻转最多一次使路径不连通
 */

// @lc code=start
class Solution {
private:
    bool dfs(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        if (x == m - 1 && y == n - 1) return true;
        grid[x][y] = 0;
        return x < m - 1 && grid[x+1][y] && dfs(grid, x + 1, y) || y < n - 1 && grid[x][y+1] && dfs(grid, x, y + 1);
    }
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        return !dfs(grid, 0, 0) || !dfs(grid, 0, 0);
    }
};
// @lc code=end

