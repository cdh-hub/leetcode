/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> g;
    bool valid = true;
    vector<int> visited;
    void createGraph(int n) {
        g.resize(n);
        visited.resize(n);
    }
    void addEdge(int u, int v) {
        g[u].push_back(v);
    }
    void dfs(int v) {
        if (visited[v] == 0) {
            visited[v] = -1;
            for (auto u: g[v]) {
                dfs(u);
            }
            visited[v] = 1;
        }
        else if (visited[v] == -1) {
            valid = false;
        }
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        createGraph(numCourses);
        for (auto pre: prerequisites) {
            addEdge(pre[1], pre[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            dfs(i);
        }
        return valid;
    }
};
// @lc code=end

