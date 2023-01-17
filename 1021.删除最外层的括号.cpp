/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> stk;
        string s1;
        for (char c : s) {
            if (c == '(') {
                if (!stk.empty()) {
                    s1.push_back(c);
                }
                stk.push(c);
            }
            else {
                if (stk.size() > 1) {
                    s1.push_back(c);
                }
                stk.pop();
            }
        }
        return s1;
    }
};
// @lc code=end

