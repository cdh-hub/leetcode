/*
 * @lc app=leetcode.cn id=1746 lang=cpp
 *
 * [1746] 经过一次操作后的最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();
        int dp[n][2];
        dp[0][0] = nums[0];
        dp[0][1] = nums[0]*nums[0];
        int ans = dp[0][1];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0] + nums[i], nums[i]);
            dp[i][1] = max(max(dp[i-1][0] + nums[i]*nums[i], dp[i-1][1] + nums[i]), nums[i]*nums[i]);
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
};
// @lc code=end

