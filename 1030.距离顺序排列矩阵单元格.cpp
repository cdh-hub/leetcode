/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> res;
        int n = max(rCenter, rows-rCenter-1) + max(cCenter, cols-cCenter-1);
        res.push_back({rCenter, cCenter});
        int dir[2][4][2] = {{{0, -1}, {-1, 0}, {0, 1}, {1, 0}}, {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}}};
        for (int i = 1; i <= n; i++) {
            for (int t = 0; t < 4; t++) {
                for (int r = rCenter + dir[0][t][0] * i, c = cCenter + dir[0][t][1] * i;
                r != rCenter + dir[0][(t+1)%4][0] * i; r += dir[1][t][0], c += dir[1][t][1]) {
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        res.push_back({r, c});
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

