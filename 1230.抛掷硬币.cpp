/*
 * @lc app=leetcode.cn id=1230 lang=cpp
 *
 * [1230] 抛掷硬币
 */

// @lc code=start
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        double dp[n+1][target+1];
        dp[0][0] = 1;
        for (int j = 1; j <= n; j++) {
            dp[j][0] = dp[j-1][0]*(1-prob[j-1]);
        }
        for (int i = 1; i <= target; i++) {
            dp[0][i] = 0;
            for (int j = 1; j <= n; j++) {
                dp[j][i] = dp[j-1][i-1]*prob[j-1] + dp[j-1][i]*(1-prob[j-1]);
            }
        }
        return dp[n][target];
    }
};
// @lc code=end

