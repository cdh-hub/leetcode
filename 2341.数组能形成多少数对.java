/*
 * @lc app=leetcode.cn id=2341 lang=java
 *
 * [2341] 数组能形成多少数对
 */

// @lc code=start
class Solution {
    public int[] numberOfPairs(int[] nums) {
        int[] count = new int[101];
        // for (int i = 0; i < 101; i++) count[i] = 0;
        int[] ans = new int[2];
        // ans[0] = 0;
        // ans[1] = 0;
        for (int num: nums) {
            if (count[num] == 0) {
                count[num]++;
                ans[1]++;
            }
            else {
                count[num] = 0;
                ans[0]++;
                ans[1]--;
            }
        }
        return ans;
    }
}
// @lc code=end

