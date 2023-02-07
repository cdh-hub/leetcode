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
        int dp1[n+1], dp2[n+1];
        int maxDP1 = 0, maxNum = nums[0];
        dp1[0] = 0;
        dp2[0] = 0;
        for (int i = 0; i < n; i++) {
            maxNum = max(maxNum, nums[i]);
            if (nums[i] == 0) {
                dp1[i+1] = 0;
                dp2[i+1] = 0;
            }
            else if (nums[i] > 0) {
                if (dp1[i] > 0) dp1[i+1] = dp1[i] * nums[i];
                else dp1[i+1] = nums[i];
                maxDP1 = max(maxDP1, dp1[i+1]);
                dp2[i+1] = dp2[i] * nums[i];
            }
            else {
                if (dp1[i] > 0) dp2[i+1] = dp1[i] * nums[i];
                else dp2[i+1] = nums[i];
                dp1[i+1] = dp2[i] * nums[i];
                maxDP1 = max(maxDP1, dp1[i+1]);
            }
        }
        if (maxDP1 == 0 && maxNum < 0) return maxNum;
        return maxDP1;
    }
};
// @lc code=end

