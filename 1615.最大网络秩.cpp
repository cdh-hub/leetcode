/*
 * @lc app=leetcode.cn id=1615 lang=cpp
 *
 * [1615] 最大网络秩
 */

// @lc code=start
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        bool g[n][n];
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) g[i][j] = false;
        for (auto& road: roads) {
            g[road[0]][road[1]] = true;
            g[road[1]][road[0]] = true;
            cnt[road[0]]++;
            cnt[road[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            if (i != j) ans = max(ans, cnt[i]+cnt[j]-g[i][j]);
        }
        return ans;
    }
};
// @lc code=end

