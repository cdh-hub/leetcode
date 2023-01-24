/*
 * @lc app=leetcode.cn id=265 lang=cpp
 *
 * [265] 粉刷房子 II
 */

// @lc code=start
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        int minCosts[2][k];
        for (int i = 0; i < k; i++) {
            minCosts[0][i] = costs[0][i];
        }
        
        int tag = 0;
        for (int i = 1; i < n; i++) {
            int minindex1 = -1, minindex2 = -1;
            int minCost1 = INT_MAX / 2, minCost2 = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (minCosts[tag][j] < minCost1) {
                    minCost2 = minCost1;
                    minCost1 = minCosts[tag][j];
                    minindex2 = minindex1;
                    minindex1 = j;
                }
                else if (minCosts[tag][j] < minCost2) {
                    minCost2 = minCosts[tag][j];
                    minindex2 = j;
                }
            }
            for (int j = 0; j < k; j++) {
                minCosts[1-tag][j] = costs[i][j] + (minindex1 == j ? minCost2 : minCost1);
            }
            tag = 1 - tag;
        }
        int res = minCosts[tag][0];
        for (int i = 0; i < k; i++) {
            res = min(res, minCosts[tag][i]);
        }
        return res;
    }
};
// @lc code=end

