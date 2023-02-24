/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int a = 0, b = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            int c = max(b, nums[i] + a);
            a = b;
            b = c;
        }
        int ans = b;
        a = 0; b = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int c = max(b, nums[i] + a);
            a = b;
            b = c;
        }
        return max(ans, b);
    }
};
// @lc code=end

