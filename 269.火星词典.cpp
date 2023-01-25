/*
 * @lc app=leetcode.cn id=269 lang=cpp
 *
 * [269] 火星词典
 */

// @lc code=start
class Solution {
private:
    string ans;
    bool valid = true;
    void dfs(vector<vector<char>>& g, char ch, unordered_map<char, int> map, vector<int>& visited) {
        if (!valid || visited[map[ch]] == -1) return;
        if (visited[map[ch]] == 1) {
            valid = false;
            return;
        }
        visited[map[ch]] = 1;
        for (auto ch2 : g[map[ch]]) {
            dfs(g, ch2, map, visited);
        }
        ans = ch + ans;
        visited[map[ch]] = -1;
    }
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> map;
        int n = 0;
        for (string s: words) {
            for (char ch: s) {
                if (map.count(ch) == 0) {
                    map[ch] = n++;
                }
            }
        }
        vector<vector<char>> g(n);
        for (int i = 1; i < words.size(); i++) {
            int j = 0;
            while (j < words[i-1].size() && j < words[i].size() && words[i-1][j] == words[i][j]) {
                j++;
            }
            if (j < words[i-1].size() && j == words[i].size()) return "";
            if (j == words[i-1].size()) continue;
            g[map[words[i-1][j]]].push_back(words[i][j]);
        }
        vector<int> visited(n, 0);
        for (auto& [ch,_]: map) {
            dfs(g, ch, map, visited);
        }
        return valid ? ans : "";
    }
};
// @lc code=end

