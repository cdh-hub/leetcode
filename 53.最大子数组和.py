#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子数组和
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum = 0
        maxSum = nums[0]
        for n in nums:
            sum = sum + n
            maxSum = max(maxSum, sum)
            sum = max(sum, 0)
        return maxSum
# @lc code=end

