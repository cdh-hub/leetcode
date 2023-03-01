/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), ans = 0;
        for (char ch: s1) ans += ch;
        for (char ch: s2) ans += ch;
        pair<int, int> dp[n1+1][n2+1];
        for (int i = 0; i <= n1; i++) dp[i][0] = make_pair(0, 0);
        for (int j = 0; j <= n2; j++) dp[0][j] = make_pair(0, 0);
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = make_pair(dp[i-1][j-1].first+1, dp[i-1][j-1].second + s1[i-1]);
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return ans - 2*dp[n1][n2].second;
    }
};
// @lc code=end

