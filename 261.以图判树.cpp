/*
 * @lc app=leetcode.cn id=261 lang=cpp
 *
 * [261] 以图判树
 */

// @lc code=start
class Solution {
private:
    int* set;
    int find(int x) {
        if (set[x] == x) return x;
        return set[x] = find(set[x]);
    }
    void un(int x, int y) {
        set[find(x)] = find(y);
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() < n - 1) return false;
        set = new int[n];
        for (int i = 0; i < n; i++) set[i] = i;
        for (auto edge: edges) {
            if (find(edge[0]) == find(edge[1])) return false;
            else un(edge[0], edge[1]);
        }
        return true;
    }
};
// @lc code=end

