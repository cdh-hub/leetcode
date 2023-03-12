/*
 * @lc app=leetcode.cn id=1130 lang=cpp
 *
 * [1130] 叶值的最小代价生成树
 */

// @lc code=start
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int dp[n][n], dp_max[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
            dp_max[i][i] = arr[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i+len-1 < n; i++) {
                dp[i][i+len-1] = INT_MAX;
                dp_max[i][i+len-1] = max(dp_max[i][i], dp_max[i+1][i+len-1]);
                for (int mid = i; mid < i+len-1; mid++) {
                    dp[i][i+len-1] = min(dp[i][i+len-1], dp_max[i][mid]*dp_max[mid+1][i+len-1] + dp[i][mid] + dp[mid+1][i+len-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

