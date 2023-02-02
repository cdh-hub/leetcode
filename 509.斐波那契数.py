#
# @lc app=leetcode.cn id=509 lang=python3
#
# [509] 斐波那契数
#

# @lc code=start
class Solution:
    def fib(self, n: int) -> int:
        a = 0
        b = 1
        for i in range(n):
            c = a + b
            a = b
            b = c
        return a
# @lc code=end

