# @before-stub-for-debug-begin
from python3problem32 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=32 lang=python3
#
# [32] 最长有效括号
#

# @lc code=start
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        maxLen = 0
        dp = [0]*len(s)
        for i in range(1, len(s)):
            if s[i] == ')' and s[i-1] == '(': 
                if i >= 2:
                    dp[i] = dp[i-2] + 2
                else:
                    dp[i] = 2
            elif s[i] == ')' and s[i-1] == ')':
                if i-1-dp[i-1] >= 0 and s[i-1-dp[i-1]] == '(':
                    if i-2-dp[i-1] >= 0:
                        dp[i] = dp[i-1] + 2 + dp[i-2-dp[i-1]]
                    else:
                        dp[i] = dp[i-1] + 2
            maxLen = max(maxLen, dp[i])
        return maxLen
# @lc code=end

