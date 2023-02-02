# @before-stub-for-debug-begin
from python3problem55 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=55 lang=python3
#
# [55] 跳跃游戏
#

# @lc code=start
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxLen = 0
        for i in range(len(nums)):
            if i > maxLen:
                break
            maxLen = max(maxLen, i + nums[i])
        return maxLen >= len(nums)-1
# @lc code=end

