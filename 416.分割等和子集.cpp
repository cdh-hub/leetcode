/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n: nums) {
            sum += n;
        }
        if (sum & 1) return false;
        sum >>= 1;
        int n = nums.size();
        bool dp[sum+1];
        dp[0] = true;
        for (int i = 1; i <= sum; i++) dp[i] = false;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};
// @lc code=end

