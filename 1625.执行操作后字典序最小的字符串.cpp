/*
 * @lc app=leetcode.cn id=1625 lang=cpp
 *
 * [1625] 执行操作后字典序最小的字符串
 */

// @lc code=start
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;
        for (int i = 0; i < n / gcd(n, b); i++) {
            s = s.substr(n-b) + s.substr(0, n-b);
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= ((b&1)?9:0); k++) {
                    string t = s;
                    for (int o = 0; o < n; o += 2) {
                        t[o] = ((t[o] - '0' + k*a) % 10) + '0';
                    }
                    for (int o = 1; o < n; o += 2) {
                        t[o] = ((t[o] - '0' + j*a) % 10) + '0';
                    }
                    ans = min(ans, t);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

