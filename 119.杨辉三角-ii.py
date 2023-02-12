#
# @lc app=leetcode.cn id=119 lang=python3
#
# [119] 杨辉三角 II
#

# @lc code=start
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]
        pre = [1, 1]
        # if rowIndex == 1:
        #     return pre
        for i in range(2, rowIndex+1):
            cur = [1] * (i+1)
            for j in range(1, i):
                cur[j] = pre[j-1] + pre[j]
            pre = cur
        return pre

# @lc code=end

