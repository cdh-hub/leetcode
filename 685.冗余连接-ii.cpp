/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
class Solution {
private:
    int find(vector<int>& vec, int node) {
        if (vec[node] == node) return node;
        return vec[node] = find(vec, vec[node]);
    }
    void un(vector<int>& vec, int node1, int node2) {
        vec[find(vec, vec[node1])] = find(vec, vec[node2]);
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> root(edges.size()+1);
        vector<int> parent(edges.size()+1);
        vector<int> res1, res2, res3;
        for (int i = 0; i < root.size(); i++) {
            root[i] = i;
        }
        bool conflict = false, circle = false;
        for (auto edge: edges) {
            if (parent[edge[1]]) {
                res1 = {edge[0], edge[1]};
                res2 = {parent[edge[1]], edge[1]};
                conflict = true;
            }
            else if (find(root, edge[0]) == find(root, edge[1])) {
                res3 = {edge[0], edge[1]};
                circle = true;
            }
            else {
                parent[edge[1]] = edge[0];
                un(root, edge[0], edge[1]);
            }
        }
        if (conflict && !circle) return res1;
        else if (!conflict && circle) return res3;
        else {
            if (find(root, res1[0]) == find(root, res1[1])) return res1;
            else return res2;
        }
    }
};
// @lc code=end

