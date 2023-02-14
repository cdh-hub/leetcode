/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> ans;
    vector<string> cur;
    void dfs(string& s, int pos) {
        if (pos == s.size()) ans.push_back(cur);
        for (int i = pos; i < s.size(); i++) {
            if (check(s.substr(pos, i-pos+1))) {
                cur.push_back(s.substr(pos, i-pos+1));
                dfs(s, i+1);
                cur.pop_back();
            }
        }
    }
    bool check(const string& s) const {
        for (int i = 0; i < s.size()/2; i++) {
            if (s[i] != s[s.size()-i-1]) return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }
};
// @lc code=end

