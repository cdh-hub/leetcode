/*
 * @lc app=leetcode.cn id=2522 lang=cpp
 *
 * [2522] 将字符串分割成值不超过 K 的子字符串
 */

// @lc code=start
class Solution {
public:
    int minimumPartition(string s, int k) {
        string kstr = to_string(k);
        int n = s.size(), m = kstr.size();
        if (n < m) return 1;
        vector<int> dp(n+1, 1);
        dp[0] = 0;
        for (int i = m - 1; i < n; i++) {
            if (s[i]-'0' > k) return -1;
            if (s.substr(i - m + 1, m) <= kstr)
                dp[i+1] = min(dp[i]+1, dp[i-m+1]+1);
            else dp[i+1] = min(dp[i]+1, dp[i-m+2]+1);
        }
        return dp[n];
    }
};
// @lc code=end

