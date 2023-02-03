#
# @lc app=leetcode.cn id=746 lang=python3
#
# [746] 使用最小花费爬楼梯
#

# @lc code=start
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        a = 0
        b = 0
        for i in range(len(cost)-1):
            c = min(a + cost[i], b + cost[i+1])
            a = b
            b = c
        return b

# @lc code=end

