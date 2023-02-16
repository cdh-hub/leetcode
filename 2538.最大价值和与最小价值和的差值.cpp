/*
 * @lc app=leetcode.cn id=2538 lang=cpp
 *
 * [2538] 最大价值和与最小价值和的差值
 */

// @lc code=start
class Solution {
private:
    int n;
    vector<vector<int>> g;
    long long ans = 0;
    vector<int> price;
    pair<long long, long long> dfs(int node, int father) {
        long long maxPath1 = price[node], maxPath2 = 0;
        for (auto v: g[node]) {
            if (v != father) {
                auto p = dfs(v, node);
                long long path1 = p.first, path2 = p.second;
                ans = max(ans, max(path1 + maxPath2, path2 + maxPath1));
                maxPath1 = max(maxPath1, path1 + price[node]);
                maxPath2 = max(maxPath2, path2 + price[node]);
            }
        }
        return make_pair(maxPath1, maxPath2);
    }
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        g.resize(n);
        this->price = price;
        this->n = n;
        for (auto edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        return ans;
    }
};
// @lc code=end

