/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int longestIndex = 0;
        for (int i = 0; i < nums.size() && i <= longestIndex; i++) {
            longestIndex = max(longestIndex, i + nums[i]);
        }
        return longestIndex >= nums.size() - 1;
    }
};
// @lc code=end

