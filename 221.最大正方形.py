#
# @lc app=leetcode.cn id=221 lang=python3
#
# [221] 最大正方形
#

# @lc code=start
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        prefix = [[0]*(n+1) for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                prefix[i][j] = (0 if matrix[i-1][j-1] == '0' else 1) + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]
        for l in range(min(m, n), 0, -1):
            for i in range(m-l+1):
                for j in range(n-l+1):
                    if prefix[i+l][j+l] - prefix[i][j+l] - prefix[i+l][j] + prefix[i][j] == l*l:
                        return l*l
        return 0
# @lc code=end

