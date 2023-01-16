/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> res = image;
        int n = res.size();
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n / 2; i++) {
                swap(res[j][i], res[j][n-i-1]);
            }
            for (int i = 0; i < n; i++) {
                res[j][i] ^= 1;
            }
        }
        return res;
    }
};
// @lc code=end

