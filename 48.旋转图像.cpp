/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //x, y -> y, n-x-1 -> n-x-1, n-y-1 -> n-y-1, x
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n-i-1; j++) {
                swap(matrix[i][j], matrix[n-j-1][i]);
                swap(matrix[n-j-1][i], matrix[n-i-1][n-j-1]);
                swap(matrix[n-i-1][n-j-1], matrix[j][n-i-1]);
            }
        } 
    }
};
// @lc code=end

