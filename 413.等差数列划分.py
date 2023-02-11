#
# @lc app=leetcode.cn id=413 lang=python3
#
# [413] 等差数列划分
#

# @lc code=start
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return 0
        delta = nums[1] - nums[0]
        longest = 0
        sum = 0
        for i in range(2, len(nums)):
            if nums[i] - nums[i-1] == delta:
                longest += 1
            else:
                sum += (1 + longest) * longest // 2
                delta = nums[i] - nums[i-1]
                longest = 0
        sum += (1 + longest) * longest // 2
        return sum

# @lc code=end

