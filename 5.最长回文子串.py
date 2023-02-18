#
# @lc app=leetcode.cn id=5 lang=python3
#
# [5] 最长回文子串
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        s1 = "@#" + "#".join(s) + "#$"
        n = len(s1)
        dp = [0] * n
        ans = s[0]
        center, maxRight = 0, 0
        for i in range(1, n-1):
            if i < maxRight:
                dp[i] = min(maxRight-i, dp[2*center-i])
            while s1[i+dp[i]+1] == s1[i-dp[i]-1]:
                dp[i] += 1
            if i + dp[i] > maxRight:
                center, maxRight = i, i + dp[i]
            if (dp[i] > len(ans)):
                ans = s[(i-dp[i]-1)//2:(i+dp[i]-1)//2]
        return ans
# @lc code=end

