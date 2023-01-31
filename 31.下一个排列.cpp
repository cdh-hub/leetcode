/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while (i > 0 && nums[i-1] >= nums[i]) i--;
        if (i == 0) reverse(nums.begin()+i, nums.end());
        else {
            int j = i - 1;
            while (j + 1 < nums.size() && nums[j+1] > nums[i-1]) j++;
            swap(nums[i-1], nums[j]);
            reverse(nums.begin()+i, nums.end());
        }
    }
};
// @lc code=end

