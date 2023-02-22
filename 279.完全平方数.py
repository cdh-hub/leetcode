#
# @lc app=leetcode.cn id=279 lang=python3
#
# [279] 完全平方数
#

# @lc code=start
class Solution:
    def numSquares(self, n: int) -> int:
        squares = []
        i = 0
        while i*i <= n:
            squares.append(i*i)
            i += 1
        dp = [0] * (n+1)
        dp[0] = 0
        for j in range(1, n+1):
            dp[j] = j
            i = 0
            while i < len(squares) and squares[i] <= j:
                dp[j] = min(dp[j], dp[j-squares[i]]+1)
                i += 1
        return dp[n]
# @lc code=end

