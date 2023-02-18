#
# @lc app=leetcode.cn id=376 lang=python3
#
# [376] 摆动序列
#

# @lc code=start
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        dp1 = [1] * n
        dp2 = [1] * n
        ans = 1
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp1[i] = max(dp1[i], dp2[j]+1)
                elif nums[j] > nums[i]:
                    dp2[i] = max(dp2[i], dp1[j]+1)
            ans = max(ans, max(dp1[i], dp2[i]))
        return ans
# @lc code=end

