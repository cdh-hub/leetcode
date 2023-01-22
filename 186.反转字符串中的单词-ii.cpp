/*
 * @lc app=leetcode.cn id=186 lang=cpp
 *
 * [186] 反转字符串中的单词 II
 */

// @lc code=start
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int pre = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin()+pre, s.begin()+i);
                pre = i + 1;
            }
        }
        reverse(s.begin()+pre, s.end());
    }
};
// @lc code=end

