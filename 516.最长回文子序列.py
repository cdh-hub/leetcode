#
# @lc app=leetcode.cn id=516 lang=python3
#
# [516] 最长回文子序列
#

# @lc code=start
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[0]*n for _ in range(n)]
        for i in range(n):
            dp[i][i] = 1
        for l in range(2, n+1):
            for i in range(n-l+1):
                if s[i] == s[i+l-1]:
                    dp[i][i+l-1] = dp[i+1][i+l-2]+2
                else:
                    dp[i][i+l-1] = max(dp[i][i+l-2], dp[i+1][i+l-1])
        return dp[0][n-1]        
# @lc code=end

