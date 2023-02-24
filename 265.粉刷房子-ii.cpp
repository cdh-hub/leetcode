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
        int* dp1 = new int[k], *dp2 = new int[k];
        for (int i = 0; i < k; i++) dp1[i] = 0;
        int min1 = 0, min2 = 0;
        int min1_ind = 0, min2_ind = 1;
        for (int i = 0; i < n; i++) {
            int new_min1_ind = 0, new_min2_ind = 1;
            int new_min1 = INT_MAX, new_min2 = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (j == min1_ind) dp2[j] = min2 + costs[i][j];
                else dp2[j] = min1 + costs[i][j];
                if (dp2[j] <= new_min1) {
                    new_min2 = new_min1;
                    new_min2_ind = new_min1_ind;
                    new_min1 = dp2[j];
                    new_min1_ind = j;
                }
                else if (dp2[j] < new_min2) {
                    new_min2 = dp2[j];
                    new_min2_ind = j;
                }
            }
            min1 = new_min1;
            min2 = new_min2;
            min1_ind = new_min1_ind;
            min2_ind = new_min2_ind;
            swap(dp1, dp2);
        }
        delete[] dp1;
        delete[] dp2;
        return min1;
    }
};
// @lc code=end

