/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> g(m * n);
        vector<int> degree(m * n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 && matrix[i-1][j] > matrix[i][j]) {
                    g[i*n+j].push_back((i-1)*n+j);
                    degree[(i-1)*n+j]++;
                }
                if (i < m - 1 && matrix[i+1][j] > matrix[i][j]) {
                    g[i*n+j].push_back((i+1)*n+j);
                    degree[(i+1)*n+j]++;
                }
                if (j > 0 && matrix[i][j-1] > matrix[i][j]) {
                    g[i*n+j].push_back(i*n+j-1);
                    degree[i*n+j-1]++;
                }
                if (j < n - 1 && matrix[i][j+1] > matrix[i][j]) {
                    g[i*n+j].push_back(i*n+j+1);
                    degree[i*n+j+1]++;
                }
            }
        }
        queue<int> q;
        int cnt1 = 0, cnt2;
        for (int i = 0; i < m * n; i++) {
            if (degree[i] == 0) {
                q.push(i);
                cnt1++;
            }
        }
        int pathLen = 0;
        while (!q.empty()) {
            cnt2 = cnt1;
            cnt1 = 0;
            while (cnt2--) {
                int v = q.front();
                for (int u: g[v]) {
                    degree[u]--;
                    if (degree[u] == 0) {
                        q.push(u);
                        cnt1++;
                    }
                }
                q.pop();
            }
            pathLen++;
        }
        return pathLen;
    }
};
// @lc code=end

