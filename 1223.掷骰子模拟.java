/*
 * @lc app=leetcode.cn id=1223 lang=java
 *
 * [1223] 掷骰子模拟
 */

// @lc code=start
class Solution {
    private static int MOD = 1000000000+7;
    public int dieSimulator(int n, int[] rollMax) {
        int[][] dp = new int[6][n];
        int[] sum = new int[n];
        sum[0] = 0;
        for (int j = 0; j < 6; j++) {
            dp[j][0] = (rollMax[j] >= 1 ? 1 : 0);
            sum[0] = (sum[0] + dp[j][0]) % MOD;
        }
        for (int i = 1; i < n; i++) {
            sum[i] = 0;
            for (int j = 0; j < 6; j++) {
                int sub = (i-rollMax[j]-1 >= 0 ? (sum[i-rollMax[j]-1] + MOD - dp[j][i-rollMax[j]-1]) % MOD : (i == rollMax[j] ? dp[j][0] : 0));
                dp[j][i] = (sum[i-1] + MOD - sub) % MOD;
                sum[i] = (sum[i] + dp[j][i]) % MOD;
            }
        }
        return sum[n-1];
    }
}
// @lc code=end

