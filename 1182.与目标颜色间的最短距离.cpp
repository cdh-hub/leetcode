/*
 * @lc app=leetcode.cn id=1182 lang=cpp
 *
 * [1182] 与目标颜色间的最短距离
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        int record1[n][3], record2[n][3];
        for (int i = 0; i < 3; i++) record1[0][i] = -1;
        for (int i = 0; i < 3; i++) record2[n-1][i] = -1;
        record1[0][colors[0]-1] = 0;
        record2[n-1][colors[n-1]-1] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (record1[i-1][j] == -1) record1[i][j] = -1;
                else record1[i][j] = record1[i-1][j] + 1;
                record1[i][colors[i]-1] = 0;
            }
        }
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                if (record2[i+1][j] == -1) record2[i][j] = -1;
                else record2[i][j] = record2[i+1][j] + 1;
                record2[i][colors[i]-1] = 0;
            }
        }
        vector<int> ans;
        for (auto q: queries) {
            ans.emplace_back(min(record1[q[0]][q[1]-1], record2[q[0]][q[1]-1]) == -1 ? max(record1[q[0]][q[1]-1], record2[q[0]][q[1]-1]) : min(record1[q[0]][q[1]-1], record2[q[0]][q[1]-1]));
        }
        return ans;
    }
};
// @lc code=end

