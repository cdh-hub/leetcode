/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int dp_l[n], dp_r[n];
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                dp_l[i] = -1;
            }
            else {
                dp_l[i] = stk.top();
            }
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();        
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                dp_r[i] = n;
            }
            else {
                dp_r[i] = stk.top();
            }
            stk.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, heights[i] * (dp_r[i] - dp_l[i] - 1));
        }
        return maxArea;
    }
};
// @lc code=end

