#
# @lc app=leetcode.cn id=1567 lang=python3
#
# [1567] 乘积为正数的最长子数组长度
#

# @lc code=start
class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        maxNum, num1, num2 = 0, 0, 0
        for num in nums:
            if num == 0:
                num1, num2 = 0, 0
            elif num > 0:
                num1, num2 = num1 + 1, num2 + 1 if num2 != 0 else 0
            else:
                num1, num2 = num2 + 1 if num2 != 0 else 0, num1 + 1
            maxNum = max(maxNum, num1)
        return maxNum
# @lc code=end

