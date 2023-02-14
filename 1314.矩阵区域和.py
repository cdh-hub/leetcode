#
# @lc app=leetcode.cn id=1314 lang=python3
#
# [1314] 矩阵区域和
#

# @lc code=start
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        preSum = [[0 for i in range(n+1)] for j in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                preSum[i][j] = mat[i-1][j-1] + preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1]
        ans = [[0 for i in range(n)] for j in range(m)]
        for i in range(m):
            for j in range(n):
                a = i+k+1 if i+k+1 <= m else m
                b = j+k+1 if j+k+1 <= n else n
                c = i-k if i-k >= 0 else 0
                d = j-k if j-k >= 0 else 0
                ans[i][j] = preSum[a][b] - preSum[a][d] - preSum[c][b] + preSum[c][d]
        return ans
# @lc code=end

