/*
 * @lc app=leetcode.cn id=1798 lang=java
 *
 * [1798] 你能构造出连续值的最大数目
 */

// @lc code=start
class Solution {
    public int getMaximumConsecutive(int[] coins) {
        Arrays.sort(coins);
        int dp = 0;
        for (int i = 0; i < coins.length; i++) {
            if (dp < coins[i] - 1) break;
            dp += coins[i];
        }
        return dp + 1;
    }
}
// @lc code=end

