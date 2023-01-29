/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto ch: s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            }
            else {
                if (stk.empty()) return false;
                if (ch == ')' && stk.top() == '(' ||
                    ch == ']' && stk.top() == '[' ||
                    ch == '}' && stk.top() == '{') {
                    stk.pop();
                }
                else return false;
            }
        }
        return stk.empty();
    }
};
// @lc code=end

