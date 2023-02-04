#
# @lc app=leetcode.cn id=213 lang=python3
#
# [213] 打家劫舍 II
#

# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        max1 = 0
        max2 = 0
        for i in range(len(nums) - 1):
            max3 = nums[i] + max1
            max1 = max2
            max2 = max(max2, max3)
        ans = max2
        max1 = 0
        max2 = 0
        for i in range(1, len(nums) - 2):
            max3 = nums[i] + max1
            max1 = max2
            max2 = max(max2, max3)
        return max(ans, max2 + nums[-1])
# @lc code=end

