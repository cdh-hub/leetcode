/*
 * @lc app=leetcode.cn id=1626 lang=cpp
 *
 * [1626] 无矛盾的最佳球队
 */

// @lc code=start
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        pair<int, int> a[n];
        for (int i = 0; i < n; i++) a[i] = make_pair(scores[i], ages[i]);
        sort(a, a+n);
        int dp[n], ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                if (a[j].second <= a[i].second) dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += a[i].first;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

