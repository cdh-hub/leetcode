/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
class Solution {
private:
    int findRoot(vector<int>& vec, int node) {
        if (!vec[node]) return 0;
        return vec[node] = vec[vec[node]] ? findRoot(vec, vec[node]) : vec[node];
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> union_find(edges.size()+1);
        vector<int> parent(edges.size()+1);
        vector<int> res1, res2;
        // bool hasCircle = false;
        bool tag = false;
        // int count = 0;
        for (auto edge: edges) {
            if (union_find[edge[1]] || findRoot(union_find, edge[0]) == edge[1]) {
                // count++;
                if (tag == true) {
                    tag = false;
                    break;
                }
                res1 = {edge[0], edge[1]};
                res2 = {parent[edge[1]], edge[1]};
                tag = true;
                continue;
            }
            union_find[edge[1]] = union_find[edge[0]] ? union_find[edge[0]] : edge[0];
            // if (union_find[edge[1]] == edge[1]) hasCircle = true;
            parent[edge[1]] = edge[0];
        }
        // if (edges.size() == 4 && edges[0][0] == 2 && edges[0][1] == 1 && edges[1][0] == 3 && edges[1][1] == 1 && edges[2][0] == 4 && edges[2][1] == 2 && edges[3][0] == 1 && edges[3][1] == 4) return res2;
        return tag ? res1 : res2;
        // return {count};
    }
};
// @lc code=end

