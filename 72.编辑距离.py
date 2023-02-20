#
# @lc app=leetcode.cn id=72 lang=python
#
# [72] 编辑距离
#

# @lc code=start
class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m, n = len(word1), len(word2)
        dp = [[0]*(n+1) for _ in range(m+1)]
        for i in range(m+1):
            for j in range(n+1):
                if i != 0 or j != 0:
                    if i == 0:
                        dp[i][j] = dp[i][j-1]+1
                    elif j == 0:
                        dp[i][j] = dp[i-1][j]+1
                    elif word1[i-1] == word2[j-1]:
                        dp[i][j] = dp[i-1][j-1]
                    else:
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
        return dp[m][n]
# @lc code=end

