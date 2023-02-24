/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num: nums) {
            int c = max(b, num + a);
            a = b;
            b = c;
        }
        return b;
    }
};
// @lc code=end

