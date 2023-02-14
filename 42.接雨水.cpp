/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                ans += max(0, leftMax - height[l]);
                leftMax = max(leftMax, height[l]);
                l++;
            }
            else {
                ans += max(0, rightMax - height[r]);
                rightMax = max(rightMax, height[r]);
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end

