/*
 * @lc app=leetcode.cn id=2547 lang=cpp
 *
 * [2547] 拆分数组的最小代价
 */

// @lc code=start
typedef long long ll;
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        ll cost[n+1];
        vector<vector<int>> trimmed(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            vector<int> count(n, 0);
            for (int j = i; j < n; j++) {
                count[nums[j]]++;
                if (j == i) trimmed[i][j] = 0;
                else if (count[nums[j]] == 2) trimmed[i][j] = trimmed[i][j - 1] + 2;
                else if (count[nums[j]] > 2) trimmed[i][j] = trimmed[i][j - 1] + 1;
                else trimmed[i][j] = trimmed[i][j - 1];
            }
        }
        cost[0] = 0;
        for (int i = 1; i <= n; i++) {
            ll min_cost = cost[0] + trimmed[0][i-1] + k;
            for (int j = 1; j < i; j++) {
                min_cost = min<ll>(min_cost, cost[j] + trimmed[j][i-1] + k);
            }
            cost[i] = min_cost;
        }
        return cost[n];
    }
};
// @lc code=end

