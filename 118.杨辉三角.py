#
# @lc app=leetcode.cn id=118 lang=python3
#
# [118] 杨辉三角
#

# @lc code=start
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = []
        for i in range(numRows):
            cur = [1] * (i+1)
            if i > 1:
                for j in range(1, i):
                    cur[j] = ans[-1][j-1] + ans[-1][j]
            ans.append(cur)
        return ans
# @lc code=end

