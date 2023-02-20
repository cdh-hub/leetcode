#
# @lc app=leetcode.cn id=392 lang=python3
#
# [392] 判断子序列
#

# @lc code=start
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i, n = 0, len(t)
        for ch in s:
            while i < n and t[i] != ch:
                i += 1
            if i == n:
                return False
            i += 1
        return True
# @lc code=end

