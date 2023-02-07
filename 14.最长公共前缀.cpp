/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        for (int i = 0; ; i++) {
            char cur;
            if (i < strs[0].size()) {
                cur = strs[0][i];
            }
            else return s;
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size()) return s;
                if (strs[j][i] != cur) return s;
            }
            s.push_back(cur);        
        }
        return s;
    }
};
// @lc code=end

