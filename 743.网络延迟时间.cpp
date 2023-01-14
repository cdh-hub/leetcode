/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
class Solution {
private:
    int maxtime = 0;
    int dijkstra(vector<vector<int>>& g, int k) {
        int n = g.size() - 1;
        vector<bool> record(n + 1, false);
        vector<int> dist(n + 1, INT_MAX>>1);
        dist[k] = 0;
        int maxPath = 0;
        for (int i = 0; i < n; i++) {
            int mindist = INT_MAX>>1;
            int node = -1;
            for (int j = 1; j <= n; j++) {
                if (!record[j] && dist[j] < mindist) mindist = dist[j], node = j;
            }
            if (node == -1) return -1;
            for (int j = 1; j <= n; j++) {
                if (g[node][j] > -1 && g[node][j] + dist[node] < dist[j]) {
                    dist[j] = g[node][j] + dist[node];
                }
            }
            if (dist[node] > maxPath) maxPath = dist[node];
            record[node] = true;
        }
        return maxPath;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> g(n + 1, vector<int>(n + 1, -1));
        for (auto time: times) {
            g[time[0]][time[1]] = time[2];
        }
        return dijkstra(g, k);
    }
};
// @lc code=end

