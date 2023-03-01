/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int dp[m][n];
        memset(dp, sizeof(dp), 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int a = i == 0 ? 0 : dp[i-1][j];
                int b = j == 0 ? 0 : dp[i][j-1];
                int c = i == 0 || b == 0 ? 0 : dp[i-1][j-1];
                if (text1[i] == text2[j]) {
                    dp[i][j] = c + 1;
                }
                else {
                    dp[i][j] = max(a, b);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

