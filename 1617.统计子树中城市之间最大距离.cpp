/*
 * @lc app=leetcode.cn id=1617 lang=cpp
 *
 * [1617] 统计子树中城市之间最大距离
 */

// @lc code=start
class Solution {
private:
    vector<int>* g;
    bool* select;
    vector<int> ans;
    int n;
    void backtrack(int node) {
        if (node == n+1) {
            int dis = getdis();
            if (dis > 0) ans[dis-1]++;
            return;
        }
        backtrack(node+1);
        select[node] = true;
        backtrack(node+1);
        select[node] = false;
    }
    bool* record;
    int maxdis;
    int getdis() {
        maxdis = 0;
        fill(record, record+n+1, false);
        for (int i = 1; i <= n; i++) if (select[i]) {
            dfs(i, 0);
            break;
        }
        for (int i = 1; i <= n; i++) if (select[i] && !record[i]) {
            maxdis = 0;
            break;
        }
        return maxdis;
    }
    int dfs(int node, int father) {
        record[node] = true;
        int maxLen = 0;
        for (int v: g[node]) {
            if (v != father && select[v]) {
                int len = dfs(v, node);
                maxdis = max(maxdis, len + maxLen);
                maxLen = max(maxLen, len);
            }
        }
        return maxLen+1;
    }
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        this->n = n;
        g = new vector<int>[n+1];
        select = new bool[n+1];
        record = new bool[n+1];
        ans.resize(n-1, 0);
        fill(select, select+n+1, false);
        for (auto& edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        backtrack(1);
        return ans;
    }
};
// @lc code=end

