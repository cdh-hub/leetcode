/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        auto left = s.begin(), right = s.begin();
        while (1) {
            while (right != s.end() && *right != ' ') right++;
            reverse(left, right);
            if (right == s.end()) break;
            left = ++right;
        }
        return s;
    }
};
// @lc code=end

