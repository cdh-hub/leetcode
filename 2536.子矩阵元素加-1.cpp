/*
 * @lc app=leetcode.cn id=2536 lang=cpp
 *
 * [2536] 子矩阵元素加 1
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (auto q: queries) {
            ans[q[0]][q[1]]++;
            if (q[3] + 1 < n) ans[q[0]][q[3]+1]--;
            if (q[2] + 1 < n) ans[q[2]+1][q[1]]--;
            if (q[2] + 1 < n && q[3] + 1 < n)ans[q[2]+1][q[3]+1]++;
        }
        for (int j = 1; j < n; j++) {
            ans[0][j] += ans[0][j-1];
        }
        for (int i = 1; i < n; i++) {
            ans[i][0] += ans[i-1][0];
            for (int j = 1; j < n; j++) {
                ans[i][j] += ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
            }
        }
        return ans;
    }
};
// @lc code=end

