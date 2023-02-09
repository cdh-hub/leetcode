# @before-stub-for-debug-begin
from python3problem309 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=309 lang=python3
#
# [309] 最佳买卖股票时机含冷冻期
#

from typing import List

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if (n <= 1):
            return 0
        dp = [[0]*n, [0]*n, [0]*n]
        a, b = 0, 0 
        c, d = max(0, prices[1]-prices[0]), max(0, prices[1]-prices[0])
        for i in range(2, len(prices)):
            a, b, c, d = c, d, \
                max(c, d, d+prices[i]-prices[i-1]), \
                max(d+prices[i]-prices[i-1], a)
        return max(c, d)

# @lc code=end

