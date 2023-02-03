/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = 0;
        if (m > 0) n = matrix[0].size();
        int h[n];
        for (int i = 0; i < n; i++) {
            h[i] = 0;
        }
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') h[j]++;
                else h[j] = 0;
            }
            stack<int> stk;
            int dpl[n], dpr[n];
            memset(dpl, -1, sizeof(int)*n);
            for (int j = n-1; j >= 0; j--) {
                while (!stk.empty() && h[stk.top()] >= h[j]) {
                    dpl[stk.top()] = j;
                    stk.pop();
                }
                if (!stk.empty()) {
                    dpr[j] = stk.top();
                }
                else {
                    dpr[j] = n;
                }
                stk.push(j);
            }
            for (int j = 0; j < n; j++) {
                maxArea = max(maxArea, (dpr[j] - dpl[j] - 1) * h[j]);
            }
        }
        return maxArea;
    }
};
// @lc code=end

