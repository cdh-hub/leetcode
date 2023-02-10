# @before-stub-for-debug-begin
from python3problem42 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=42 lang=python3
#
# [42] 接雨水
#

# @lc code=start
class Solution:
    def trap(self, height: List[int]) -> int:
        water, maxHeight = 0, height[0]
        for i in range(1, len(height)):
            maxHeight = max(maxHeight, height[i])
            water += maxHeight - height[i]
        cur = height[len(height)-1]
        for i in range(len(height)-1, -1, -1):
            if cur == maxHeight:
                break
            cur = max(cur, height[i])
            water -= maxHeight - cur
        return water
# @lc code=end

