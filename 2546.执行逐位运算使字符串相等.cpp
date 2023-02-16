/*
 * @lc app=leetcode.cn id=2546 lang=cpp
 *
 * [2546] 执行逐位运算使字符串相等
 */

// @lc code=start
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if (s == target) return true;
        int n = s.size();
        bool tag1 = false, tag2 = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1' && target[i] == '1') return true;
            if (target[i] == '1') tag1 = true;
            if (s[i] == '1') tag2 = true;
            if (tag1 && tag2) return true;
        }
        return false;
    }
};
// @lc code=end

