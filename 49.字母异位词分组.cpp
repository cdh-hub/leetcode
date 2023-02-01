/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> str_new(strs);
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < str_new.size(); i++) {
            sort(str_new[i].begin(), str_new[i].end());
            map[str_new[i]].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto& [_,v]:map) {
            ans.push_back(v);
        }
        return ans;
    }
};
// @lc code=end

