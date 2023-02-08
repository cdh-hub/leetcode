/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) ans = nums[i];
            count = ans == nums[i] ? count + 1 : count - 1;
        }
        return ans;
    }
};
// @lc code=end

