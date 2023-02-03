/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            a ^= nums[i];
        }
        return a;
    }
};
// @lc code=end

