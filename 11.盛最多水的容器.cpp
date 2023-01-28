/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxWater = 0;
        while (l < r) {
            maxWater = max(maxWater, min(height[l], height[r])*(r-l));
            if (height[l] < height[r]) {
                int newL = l + 1;
                while (newL < r && height[newL] <= height[l]) {
                    newL++;
                }
                l = newL;
            }
            else {
                int newR = r - 1;
                while (l < newR && height[newR] <= height[r]) {
                    newR--;
                }
                r = newR;
            }
        }
        return maxWater;
    }
};
// @lc code=end

