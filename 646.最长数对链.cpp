/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int n = pairs.size();
        int dp[n];
        dp[0] = 1;
        int maxLen = 1;
        for (int i = 1; i < pairs.size(); ++i) {
            int cur = i-1;
            while (cur >= 0 && pairs[i][0] <= pairs[cur][1]) {
                cur--;
            }
            if (cur < 0) dp[i] = 1;
            else dp[i] = dp[cur] + 1;
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};
// @lc code=end

