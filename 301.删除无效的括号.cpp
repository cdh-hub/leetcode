/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
class Solution {
private:
    unordered_set<string> ans;
    string cur;
    stack<int> stk;
    void dfs(string& s, int i, int l, int r) {
        if (s.size() - i < l + r) return;
        if (i == s.size()) {
            if (l == 0 && r == 0 && stk.empty()) ans.insert(cur);
            return;
        }
        if (l == 0 && r == 0) {
            if (s[i] == '(') {
                stk.push('(');
                cur.push_back(s[i]);
                dfs(s, i+1, 0, 0);
                cur.pop_back();
                stk.pop();
            }
            else if (s[i] == ')')  {
                if (stk.empty()) return;
                else {
                    stk.pop();
                    cur.push_back(s[i]);
                    dfs(s, i+1, 0, 0);
                    cur.pop_back();
                    stk.push('(');
                }
            }
            else {
                cur.push_back(s[i]);
                dfs(s, i+1, 0, 0);
                cur.pop_back();
            }
        }
        else {
            if (s[i] == '(') {
                if (l > 0) {
                    dfs(s, i+1, l-1, r);
                }
                stk.push('(');
                cur.push_back(s[i]);
                dfs(s, i+1, l, r);
                cur.pop_back();
                stk.pop();
            }
            else if (s[i] == ')') {
                if (r > 0) {
                    dfs(s, i+1, l, r-1);
                }
                if (!stk.empty()) {
                    stk.pop();
                    cur.push_back(s[i]);
                    dfs(s, i+1, l, r);
                    cur.pop_back();
                    stk.push('(');
                }
            }
            else {
                cur.push_back(s[i]);
                dfs(s, i+1, l, r);
                cur.pop_back();
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (char ch: s) {
            if (ch == '(') l++;
            else if (ch == ')'){
                if (l == 0) r++;
                else l--;
            }
        }
        dfs(s, 0, l, r);
        return vector<string>(ans.begin(), ans.end());
    }
};
// @lc code=end

