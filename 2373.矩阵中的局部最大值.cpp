/*
 * @lc app=leetcode.cn id=2373 lang=cpp
 *
 * [2373] 矩阵中的局部最大值
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < n-2; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int s = 0; s < 3; s++) {
                        ans[i][j] = max(ans[i][j], grid[i+k][j+s]);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

