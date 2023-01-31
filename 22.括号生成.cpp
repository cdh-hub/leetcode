/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
private:
    int stk = 0;
    string cur;
    vector<string> ans;
    void backTrack(int l, int r) {
        if (!l && !r) {
            ans.push_back(cur);
        }
        if (l > 0) {
            stk++;
            string tmp = cur;
            cur += '(';
            backTrack(l-1, r);
            cur = tmp;
            stk--;
        }
        if (stk && r > 0) {
            stk--;
            string tmp = cur;
            cur += ')';
            backTrack(l, r-1);
            cur = tmp;
            stk++;
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        backTrack(n, n);
        return ans;
    }
};
// @lc code=end

