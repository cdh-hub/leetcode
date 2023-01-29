/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    string cur = "";
    vector<string> ans;
    string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(string& digits, int pos) {
        if (pos == digits.size()) {
            if (cur.size()) {
                ans.push_back(cur);
            }
        }
        else for (auto ch: map[digits[pos]-'0']) {
            string tmp = cur;
            cur += ch;
            dfs(digits, pos + 1);
            cur = tmp;
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        dfs(digits, 0);
        return ans;
    }
};
// @lc code=end

