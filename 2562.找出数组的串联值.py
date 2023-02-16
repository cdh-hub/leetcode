#
# @lc app=leetcode.cn id=2562 lang=python3
#
# [2562] 找出数组的串联值
#

# @lc code=start
class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        n = len(nums)
        sum = 0 if n % 2 == 0 else nums[n//2]
        
        def cat(x, y):
            b = 0
            if y == 0:
                b = 1
            else:
                tmp = y
                while tmp > 0:
                    b += 1
                    tmp //= 10
            for i in range(b):
                x *= 10
            x += y
            return x
        
        
        for i in range(n//2):
            j = n - i - 1
            sum += cat(nums[i], nums[j])
        return sum
# @lc code=end

