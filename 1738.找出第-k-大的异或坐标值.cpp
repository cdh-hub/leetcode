/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 *
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp((m+1)*(n+1), 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i*(n+1)+j] = matrix[i-1][j-1] ^ dp[(i-1)*(n+1)+j] ^ dp[i*(n+1)+j-1] ^ dp[(i-1)*(n+1)+j-1];
            }
        }
        nth_element(dp.begin(), dp.begin()+(dp.size()-k), dp.end());
        return dp[dp.size()-k];
    }
};
// @lc code=end

