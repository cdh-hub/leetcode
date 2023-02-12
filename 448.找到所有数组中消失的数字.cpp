/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[(nums[i]-1)%nums.size()] += nums.size();
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= nums.size()) ans.push_back(i+1);
        }
        return ans;
    }
};
// @lc code=end

