/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int dp[n+2][n+2];
        // for (int i = 0; i < n+2; i++) dp[i][i] = 0;
        for (int i = 0; i <= n; i++) {
            for (int l = 0; l < n+1-i; l++) {
                int r = l + i + 1;
                dp[l][r] = 0;
                for (int k = l+1; k < r; k++) {
                    int lValue = l == 0 ? 1: nums[l-1],
                        rValue = r == n+1 ? 1 : nums[r-1];
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + nums[k-1]*lValue*rValue);
                }
            }
        }
        return dp[0][n+1];
    }
};
// @lc code=end

