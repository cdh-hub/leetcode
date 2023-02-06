# @before-stub-for-debug-begin
from python3problem45 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=45 lang=python3
#
# [45] 跳跃游戏 II
#

# @lc code=start
class Solution:
    def jump(self, nums: List[int]) -> int:
        i, j = 0, 0
        maxLen = min(len(nums) - 1, nums[0])
        count = 0
        while i != len(nums) - 1:
            curMaxLen = maxLen
            while j <= maxLen:
                if min(len(nums) - 1, j + nums[j]) >= curMaxLen:
                    curMaxLen = min(len(nums) - 1, j + nums[j])
                    index = j
                j = j + 1
            i = index
            maxLen = curMaxLen
            count = count + 1
        return count
# @lc code=end

