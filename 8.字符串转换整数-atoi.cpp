/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int pos = 0, n = s.size();
        while (pos < n && s[pos] == ' ') pos++;
        if (pos == n) return 0;
        int ans = 0, tag = 1;
        if (s[pos] == '-') {
            tag = 0;
            pos++;
        }
        else if (s[pos] == '+') {
            pos++;
        }
        if (tag == 1) while (pos < n && s[pos] >= '0' && s[pos] <= '9') {
            if (ans <= INT_MAX / 10 && ans*10 <= INT_MAX - (s[pos] - '0')) {
                ans = ans * 10 + (s[pos] - '0');
                pos++;
            }
            else return INT_MAX;
        }
        else while (pos < n && s[pos] >= '0' && s[pos] <= '9') {
            if (ans >= INT_MIN / 10 && ans*10 >= INT_MIN + (s[pos] - '0')) {
                ans = ans * 10 - (s[pos] - '0');
                pos++;
            }
            else return INT_MIN;
        }
        return ans;
    }
};
// @lc code=end

