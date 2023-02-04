#
# @lc app=leetcode.cn id=198 lang=python3
#
# [198] 打家劫舍
#

# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        max1 = 0
        max2 = 0
        for i in range(len(nums)):
            max3 = max1 + nums[i]
            max1 = max2
            max2 = max(max2, max3)
        return max2
# @lc code=end

