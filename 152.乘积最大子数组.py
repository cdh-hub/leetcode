# @before-stub-for-debug-begin
from python3problem152 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=152 lang=python3
#
# [152] 乘积最大子数组
#

# @lc code=start
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max1, max2, maxTotal = 0, 0, 0, 
        for num in nums:
            max1, max2 = max(max1 * num, num) if num >= 0 else max2 * num, max2 * num if num >= 0 else min(max1*num, num)
            maxTotal = max(maxTotal, max1)
        return maxTotal if maxTotal > 0 else nums[0] if len(nums) == 1 else 0
# @lc code=end

