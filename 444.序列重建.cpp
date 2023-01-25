/*
 * @lc app=leetcode.cn id=444 lang=cpp
 *
 * [444] 序列重建
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> g;
    vector<int> visited;
    bool valid = true;
    void dfs(int v) {
        if (valid && visited[v] == 0) {
            visited[v] = -1;
            for (auto u: g[v]) {
                dfs(u);
            }
            visited[v] = 1;
        }
        else if (valid && visited[v] == -1) {
            valid = false;
        }
    }
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        g.resize(nums.size() + 1);
        for (auto seq: sequences) {
            for (int i = 1; i < seq.size(); i++) {
                g[seq[i-1]].push_back(seq[i]);
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            bool tag = false;
            for (int v: g[nums[i-1]]) {
                if (v == nums[i]) {
                    tag = true;
                    break;
                }
            }
            if (!tag) return false;
        }
        visited.resize(nums.size() + 1);
        for (int i = 1; i <= nums.size(); i++) {
            dfs(i);
        }
        return valid;
    }
};
// @lc code=end

