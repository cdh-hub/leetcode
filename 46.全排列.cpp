/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, int index) {
        if (index == nums.size()) ans.push_back(nums);
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            helper(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return ans;
    }
};
// @lc code=end

