#
# @lc app=leetcode.cn id=322 lang=python3
#
# [322] 零钱兑换
#

# @lc code=start
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [0]*(amount+1)
        for i in range(1, amount+1):
            dp[i] = amount*2
            for j in range(n):
                if i-coins[j] >= 0 and dp[i-coins[j]] != -1:
                    dp[i] = min(dp[i], dp[i-coins[j]]+1)
            if dp[i] == amount*2:
                dp[i] = -1
        return dp[amount]
# @lc code=end

