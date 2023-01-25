/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
private:
    int pos;
    vector<int> order;
    vector<int> visited;
    bool valid = true;
    vector<vector<int>> g;
    void dfs(int v) {
        if (valid && visited[v] == 0) {
            visited[v] = 1;
            for (auto u: g[v]) {
                dfs(u);
            }
            order[pos--] = v;
            visited[v] = -1;
        }
        else if (valid && visited[v] == 1) {
            valid = false;
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        visited.resize(numCourses);
        order.resize(numCourses);
        pos = numCourses - 1;
        for (auto pre: prerequisites) {
            g[pre[1]].push_back(pre[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            dfs(i);
        }
        return valid ? order : vector<int>(0);
    }
};
// @lc code=end

