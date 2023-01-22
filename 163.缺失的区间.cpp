/*
 * @lc app=leetcode.cn id=163 lang=cpp
 *
 * [163] 缺失的区间
 */

// @lc code=start
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if (nums.size() == 0) {
            if (upper == lower) res.push_back(to_string(upper));
            else if (lower < upper) res.push_back(to_string(lower) + "->" + to_string(upper));
            return res;
        }
        for (int i = 0; i <= nums.size(); i++) {
            int a, b;
            if (i == nums.size()) {
                a = nums[i-1] + 1;
                b = upper;
            }
            else if (i == 0) {
                a = lower;
                b = nums[i] - 1;
            }
            else {
                a = nums[i-1] + 1;
                b = nums[i] - 1;
            }
            if (a == b) res.push_back(to_string(a));
            else if (a < b) res.push_back(to_string(a) + "->" + to_string(b));
        }
        return res;
    }
};
// @lc code=end

