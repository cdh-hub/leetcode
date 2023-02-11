#
# @lc app=leetcode.cn id=91 lang=python3
#
# [91] 解码方法
#

# @lc code=start
class Solution:
    def numDecodings(self, s: str) -> int:
        a, b = 1, 0 if s[0] == '0' else 1
        for i in range(1, len(s)):
            c = 0
            if s[i] != '0':
                c += b
            if s[i-1] != '0' and s[i-1:i+1] <= '26':
                c += a
            a, b = b, c
        return b
# @lc code=end

