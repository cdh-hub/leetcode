/*
 * @lc app=leetcode.cn id=1245 lang=cpp
 *
 * [1245] 树的直径
 */

// @lc code=start
class Solution {
private:
    vector<int>* g;
    int ans = 0;
    int dfs(int node, int father) {
        int maxLen = 0;
        for (int v: g[node]) {
            if (v != father) {
                int len = dfs(v, node);
                ans = max(ans, len + maxLen);
                maxLen = max(maxLen, len);
            }
        }
        return maxLen+1;
    }
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size();
        g = new vector<int>[n+1];
        for (auto& edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        return ans;
    }
};
// @lc code=end

