#
# @lc app=leetcode.cn id=1014 lang=python3
#
# [1014] 最佳观光组合
#

# @lc code=start
from typing import List


class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        maxi, ans = 0, 0
        for i, value in enumerate(values):
            ans = max(ans, maxi + value - i)
            maxi = max(maxi, value + i)
        return ans
# @lc code=end

