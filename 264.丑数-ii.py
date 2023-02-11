# @before-stub-for-debug-begin
from python3problem264 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=264 lang=python3
#
# [264] 丑数 II
#

# @lc code=start
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [1] * (n+1)
        p = [1,1,1]
        for i in range(2, n+1):
            dp[i] = min(dp[p[0]]*2, dp[p[1]]*3, dp[p[2]]*5)
            for j, num in enumerate([2,3,5]):
                if dp[i] == dp[p[j]]*num:
                    p[j] += 1
        return dp[n]

# @lc code=end

