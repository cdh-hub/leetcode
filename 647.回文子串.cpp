/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        string m = "@";
        for (char ch: s) {
            m.push_back('#');
            m.push_back(ch);
        }
        m += "#$";
        int dp[m.size()-2];
        int maxRight = 0, center = 0;
        for (int i = 1; i < m.size()-1; i++) {
            int r = i >= maxRight ? 1 : min(dp[2*center-i-1], maxRight - i + 1);
            while (m[i+r] == m[i-r]) r++;
            dp[i-1] = r;
            if (i + r - 1 > maxRight) {
                maxRight = i + r - 1;
                center = i;
            } 
        }
        int ans = 0;
        for (int i = 0; i < m.size()-2; i++) {
            ans += dp[i] / 2;
        }
        return ans;
    }
};
// @lc code=end

