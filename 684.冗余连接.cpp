/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
private:
    int Find(unordered_map<int, int>& mapping, int node) {
        if (mapping[node] == node) return node;
        return mapping[node] = Find(mapping, mapping[node]);
    }
    void Union(unordered_map<int, int>& mapping, int node1, int node2) {
        int root1 = Find(mapping, node1);
        int root2 = Find(mapping, node2);
        if (root1 != root2) mapping[root1] = root2;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, int> mapping;
        for (auto & edge : edges) {
            if (!mapping.count(edge[0])) {
                mapping[edge[0]] = edge[0];
            }
            if (!mapping.count(edge[1])) {
                mapping[edge[1]] = edge[1];
            }
            if (Find(mapping, edge[0]) == Find(mapping, edge[1])) return {edge[0], edge[1]};
            else Union(mapping, edge[0], edge[1]);
        }
        return {};
    }
};
// @lc code=end

