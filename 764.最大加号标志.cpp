/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 */

// @lc code=start
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> g(n, vector<int>(n, 1));
        for (auto mine : mines) {
            g[mine[0]][mine[1]] = 0;
        }
        vector<vector<int>> prefixG[4];
        for (int i = 0; i < 4; i++) {
            prefixG[i] = vector<vector<int>>(n, vector<int>(n));
        }
        for (int i = 0; i < n; i++) {
            prefixG[0][i][0] = g[i][0];
            for (int j = 1; j < n; j++) {
                prefixG[0][i][j] = g[i][j] ? prefixG[0][i][j - 1] + 1 : 0;
            }
        }
        for (int i = 0; i < n; i++) {
            prefixG[1][i][n-1] = g[i][n-1];
            for (int j = n - 2; j >= 0; j--) {
                prefixG[1][i][j] = g[i][j] ? prefixG[1][i][j + 1] + 1 : 0;
            }
        }
        for (int i = 0; i < n; i++) {
            prefixG[2][0][i] = g[0][i];
            for (int j = 1; j < n; j++) {
                prefixG[2][j][i] = g[j][i] ? prefixG[2][j - 1][i] + 1 : 0;
            }
        }
        for (int i = 0; i < n; i++) {
            prefixG[3][n-1][i] = g[n-1][i];
            for (int j = n - 2; j >= 0; j--) {
                prefixG[3][j][i] = g[j][i] ? prefixG[3][j+1][i] + 1 : 0;
            }
        }
        int maxNum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                prefixG[0][i][j] = min(min(prefixG[0][i][j], prefixG[1][i][j]), min(prefixG[2][i][j], prefixG[3][i][j]));
                if (prefixG[0][i][j] > maxNum) maxNum = prefixG[0][i][j];
            }
        }
        return maxNum;
    }
};
// @lc code=end

