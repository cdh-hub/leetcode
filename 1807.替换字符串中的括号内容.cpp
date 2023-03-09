/*
 * @lc app=leetcode.cn id=1807 lang=cpp
 *
 * [1807] 替换字符串中的括号内容
 */

// @lc code=start
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& kv: knowledge) mp[kv[0]] = kv[1];
        string ans, key;
        int status = 0;
        for (char ch: s) {
            if (ch == '(') {
                key.clear();
                status = 1;
            }
            else if (ch == ')') {
                if (mp.count(key)) ans.append(mp[key]);
                else ans.push_back('?');
                status = 0;
            }
            else if (status == 0) {
                ans.push_back(ch);
            }
            else {
                key.push_back(ch);
            }
        }
        return ans;
    }
};
// @lc code=end

