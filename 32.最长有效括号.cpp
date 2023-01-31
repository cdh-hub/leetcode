/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.size()+1], maxLen = 0;
        dp[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '(') dp[i] = 0;
            else {
                if (s[i-1] == '(') {
                    dp[i] = i-2 >= 0 ? (dp[i-2] + 2) : 2;
                    maxLen = max(dp[i], maxLen);
                }
                else {
                    if (i-1-dp[i-1] >= 0 && s[i-1-dp[i-1]] == '(') {
                        dp[i] = dp[i-1] + ((i-2-dp[i-1]) > 0 ? dp[i-2-dp[i-1]] : 0) + 2;
                        maxLen = max(dp[i], maxLen);
                    }
                    else dp[i] = 0;
                }
            }
        }
        return maxLen;
    }
};
// @lc code=end

