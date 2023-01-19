/*
 * @lc app=leetcode.cn id=582 lang=cpp
 *
 * [582] 杀掉进程
 */

// @lc code=start
class Solution {
private:
    void helper(vector<int>& res, unordered_map<int, vector<int>>& mapping, int kill) {
        res.push_back(kill);
        // if (!mapping[kill].empty()) res.insert(res.end(), mapping[kill].begin(), mapping[kill].end());
        for (auto p : mapping[kill]) {
            helper(res, mapping, p);
        }
    }
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> mapping;
        for (int i = 0; i < pid.size(); i++) {
            mapping[ppid[i]].push_back(pid[i]);
        }
        vector<int> res;
        helper(res, mapping, kill);
        return res;
    }
};
// @lc code=end

