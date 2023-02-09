#
# @lc app=leetcode.cn id=714 lang=python3
#
# [714] 买卖股票的最佳时机含手续费
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        a, b = 0, -fee
        for i in range(1, len(prices)):
            a, b = max(a, a+prices[i]-prices[i-1]-fee, b+prices[i]-prices[i-1]), \
                   max(a-fee, b+prices[i]-prices[i-1])
        return max(a, b)
# @lc code=end

