/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                if (s[i] == s[i+len-1]) dp[i][i+len-1] = 2+dp[i+1][i+len-2];
                else dp[i][i+len-1] = max(dp[i][i+len-2], dp[i+1][i+len-1]);
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

