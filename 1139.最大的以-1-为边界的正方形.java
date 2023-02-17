/*
 * @lc app=leetcode.cn id=1139 lang=java
 *
 * [1139] 最大的以 1 为边界的正方形
 */

// @lc code=start
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] preSum = new int[m+1][n+1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                preSum[i][j] = grid[i-1][j-1] + preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1];
            }
        }
        for (int len = Math.min(m, n); len > 1; len--) {
            for (int i = 0; i+len <= m; i++) {
                for (int j = 0; j+len <= n; j++) {
                    if (preSum[i+len][j+len]-preSum[i][j+len]-preSum[i+len][j]+preSum[i][j] - (preSum[i+len-1][j+len-1] - preSum[i+1][j+len-1] - preSum[i+len-1][j+1] + preSum[i+1][j+1]) == (len-1)*4) {
                        return len*len;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return 1;
            }
        }
        return 0;
    }
}
// @lc code=end

