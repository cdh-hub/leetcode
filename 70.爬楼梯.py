#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#

# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        a = 1
        b = 1
        while n > 0:
            c = a + b
            a = b
            b = c
            n = n - 1
        return a
# @lc code=end

