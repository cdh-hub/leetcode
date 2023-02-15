/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num: nums) sum += num;
        int m = nums.size()+1, n = sum*2+3; 
        int dp[m][n];
        for (int i = 0; i < n; i++) {
            dp[0][i] = 0;
        }
        dp[0][sum+1] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int a = max(0, j - nums[i-1]), b = min(sum*2+2, j+nums[i-1]);
                dp[i][j] = dp[i-1][a] + dp[i-1][b];
            }
        }
        return target+sum+1 < n && target+sum+1 >= 0 ? dp[m-1][target+sum+1] : 0;
    }
};
// @lc code=end

