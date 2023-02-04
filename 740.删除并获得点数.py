#
# @lc app=leetcode.cn id=740 lang=python3
#
# [740] 删除并获得点数
#

# @lc code=start
import collections


class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        nums.sort()
        dt = {}
        for num in nums:
            if num in dt:
                dt[num] = dt[num] + 1
            else:
                dt[num] = 1
        dp1 = 0
        dp2 = 0
        pre = None
        for key in dt:
            if pre == None or key != pre + 1:
                dp = dp2 + dt[key] * key
            else:
                dp = dp1 + dt[key] * key
            dp1 = dp2
            dp2 = max(dp2, dp)
            pre = key
        return dp2
# @lc code=end

