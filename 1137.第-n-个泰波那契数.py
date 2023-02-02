#
# @lc app=leetcode.cn id=1137 lang=python3
#
# [1137] 第 N 个泰波那契数
#

# @lc code=start
class Solution:
    def multiply(self, a: list[list[int]], b: list[list[int]]) -> list[list[int]]:
        c = []
        for i in range(len(a)):
            c_row = []
            for j in range(len(b[0])):
                s = 0
                for k in range(len(b)):
                    s = s + a[i][k] * b[k][j]
                c_row.append(s)
            c.append(c_row)
        return c

    def ksm(self, a: list[list[int]], n: int) -> list[list[int]]:
        ans = [[1,0,0],[0,1,0],[0,0,1]]
        while n > 0:
            if n % 2 == 1:
                ans = self.multiply(ans, a)
            a = self.multiply(a, a)
            n = n // 2
        return ans

    def tribonacci(self, n: int) -> int:
        ans = self.ksm([[1,1,1],[1,0,0],[0,1,0]], n)
        return self.multiply(ans, [[1],[1],[0]])[2][0]
# @lc code=end

