/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int leftMax = 0, rightMax = 0;
        for (int i = 0; i < height.size(); i++) {
            sum += max(0, leftMax - height[i]);
            leftMax = max(leftMax, height[i]);
        }
        for (int i = height.size() - 1; rightMax < leftMax; i--) {
            rightMax = max(rightMax, height[i]);
            sum -= leftMax - rightMax;
        }
        return sum;
    }
};
// @lc code=end

