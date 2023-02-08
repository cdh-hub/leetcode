/*
 * @lc app=leetcode.cn id=2527 lang=cpp
 *
 * [2527] 查询数组 Xor 美丽值
 */

// @lc code=start
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int xorTotal = 0, ans = 0;
        for (auto num: nums) xorTotal ^= num;
        for (auto num: nums) ans ^= (num & xorTotal);
        return ans;
    }
};
// @lc code=end

