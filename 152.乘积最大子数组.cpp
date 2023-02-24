/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int dp[n][2];
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] >= 0) {
                dp[i][0] = max(nums[i], dp[i-1][0] * nums[i]);
                dp[i][1] = min(nums[i], dp[i-1][1] * nums[i]);
            }
            else {
                dp[i][0] = max(nums[i], dp[i-1][1] * nums[i]);
                dp[i][1] = min(nums[i], dp[i-1][0] * nums[i]);
            }
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};
// @lc code=end

