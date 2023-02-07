# @before-stub-for-debug-begin
from python3problem918 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=918 lang=python3
#
# [918] 环形子数组的最大和
#

# @lc code=start
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n = len(nums)
        sum = nums[0]
        maxsum = sum
        totalSum = nums[0]
        for i in range(1, n):
            totalSum = totalSum + nums[i]
            if sum < 0:
                sum = 0
            sum = sum + nums[i%n]
            maxsum = max(maxsum, sum)
        sum = 0
        minsum = sum
        for i in range(1, n):
            if sum > 0:
                sum = 0
            sum = sum + nums[i%n]
            minsum = min(minsum, sum)
        return max(maxsum, totalSum - minsum)
# @lc code=end

