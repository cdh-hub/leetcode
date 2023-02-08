#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxPro, minPri = 0, prices[0]
        for i in range(1, len(prices)):
            maxPro = max(maxPro, prices[i]-minPri)
            minPri = min(minPri, prices[i])
        return maxPro
# @lc code=end

