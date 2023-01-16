/*
 * @lc app=leetcode.cn id=775 lang=cpp
 *
 * [775] 全局倒置与局部倒置
 */

// @lc code=start
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) swap(nums[i], nums[i-1]), i++;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) return false;
        }
        return true;
    }
};
// @lc code=end

