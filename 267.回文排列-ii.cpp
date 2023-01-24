/*
 * @lc app=leetcode.cn id=267 lang=cpp
 *
 * [267] 回文排列 II
 */

// @lc code=start
class Solution {
private:
    string s = "";
    vector<string> vec;
    void dfs(unordered_map<char, int>& map, char single) {
        bool tag = false;
        for (auto& [k, v]: map) {
            if (v >= 2) {
                tag = true;
                string tmp = s;
                s += k;
                map[k] -= 2;
                dfs(map, single);
                map[k] += 2;
                s = tmp;
            }
        }
        if (!tag) {
            string tmp = s;
            reverse(tmp.begin(), tmp.end());
            if (single)
                vec.push_back(s + single + tmp);
            else
                vec.push_back(s + tmp);
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> map;
        for (auto ch: s) map[ch]++;
        int cnt = 0;
        char single = '\0';
        for (auto& [k, v]: map) {
            if (v % 2) {
                cnt++;
                single = k;
            }
        }
        if (cnt > 1) return {};
        dfs(map, single);
        return vec;
    }
};
// @lc code=end

