/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxSum = max(sum, maxSum);
            if (sum < 0) sum = 0;
        }
        return maxSum;
    }
};
// @lc code=end

