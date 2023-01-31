/*
 * @lc app=leetcode.cn id=2319 lang=java
 *
 * [2319] 判断矩阵是否是一个 X 矩阵
 */

// @lc code=start
class Solution {
    public boolean checkXMatrix(int[][] grid) {
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                if (i == j || i + j + 1 == grid.length) {
                    if (grid[i][j] == 0) return false;
                }
                else {
                    if (grid[i][j] != 0) return false;
                }
            }
        }
        return true;
    }
}
// @lc code=end

