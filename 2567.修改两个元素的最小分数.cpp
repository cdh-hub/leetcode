/*
 * @lc app=leetcode.cn id=2567 lang=cpp
 *
 * [2567] 修改两个元素的最小分数
 */

// @lc code=start
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min(min(nums[n-1]-nums[2], nums[n-3]-nums[0]), nums[n-2]-nums[1]);
    }
};
// @lc code=end

